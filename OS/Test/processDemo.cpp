#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * FCFS调度算法
 * */


struct Process {
    string name;
    int arrivalTime;
    int burstTime;
    int remainingTime; // 剩余运行时间
};

vector<Process> plist; // 进程列表
int timeQuantum; // 时间片大小

// 获取进程列表
void getProcessList() {
    int n;
    cout << "请输入进程数：";
    cin >> n;
    plist.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "请输入进程 " << i + 1 << " 的名称、到达时间和执行时间：";
        cin >> plist[i].name >> plist[i].arrivalTime >> plist[i].burstTime;
        plist[i].remainingTime = plist[i].burstTime; // 初始剩余时间等于执行时间
    }
    cout << "请输入时间片大小：";
    cin >> timeQuantum;
}

// 时间片轮转调度算法
void run() {
    vector<Process> readyQueue; // 就绪队列
    int currentTime = 0; // 当前时间

    while (!plist.empty() || !readyQueue.empty()) {
        // 将到达时间小于等于当前时间的进程加入就绪队列
        for (int i = 0; i < plist.size(); i++) {
            if (plist[i].arrivalTime <= currentTime) {
                readyQueue.push_back(plist[i]);
                plist.erase(plist.begin() + i);
                i--;
            }
        }

        if (readyQueue.empty()) {
            // 如果就绪队列为空，则时间前进到下一个进程的到达时间
            int nextArrivalTime = plist[0].arrivalTime;
            for (int i = 1; i < plist.size(); i++) {
                if (plist[i].arrivalTime > currentTime && plist[i].arrivalTime < nextArrivalTime) {
                    nextArrivalTime = plist[i].arrivalTime;
                }
            }
            currentTime = nextArrivalTime;
        } else {
            // 从就绪队列取出第一个进程执行
            Process currentProcess = readyQueue.front();
            readyQueue.erase(readyQueue.begin());

            int remainingTime = currentProcess.remainingTime;
            if (remainingTime <= timeQuantum) {
                // 如果进程剩余时间小于等于时间片大小，则进程执行完毕
                currentTime += remainingTime;
                cout << "进程 " << currentProcess.name << " 在时间 " << currentTime << " 执行完毕" << endl;
            } else {
                // 否则，执行一个时间片的时间
                currentTime += timeQuantum;
                cout << "进程 " << currentProcess.name << " 在时间 " << currentTime << " 执行了一个时间片" << endl;
                // 更新进程剩余时间并放回就绪队列
                currentProcess.remainingTime -= timeQuantum;
                readyQueue.push_back(currentProcess);
            }
        }
        if (plist.empty() && readyQueue.empty()) {
            break;
        }
    }
}

int main() {
    getProcessList();
    run();

    cin.get();
    return 0;
}
