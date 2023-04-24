#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//定义进程类
class Process {
public:
    Process() {};

    Process(string n, int ct, int nt) {
        name = n;
        createTime = ct;
        needTime = nt;
    }

    string name;//进程名
    int createTime = 0;//创建时间
    int needTime = 0;//需要运行的时间
    int runTime = 0;//已经运行的时间
};

//根据创建时间排序
class MySort {
public:
    bool operator()(Process p1, Process p2) {
        return p1.createTime < p2.createTime;
    }
};


//获取所有进程
vector<Process> getProcessList() {
    vector<Process> pcb;
    int processNum;
    cout << "\n输入被调度的进程的数目：";
    cin >> processNum;
    for (int i = 0; i < processNum; i++) {
        Process p;
        cout << "\n进程号No." << i + 1 << ":";
        cout << "输入进程名:";
        cin >> p.name;
        cout << "分别输入 创建时间、需要运行时间:";
        cin >> p.createTime;
        cin >> p.needTime;
        pcb.push_back(p);
    }
    sort(pcb.begin(), pcb.end(), MySort());
    return pcb;
}

void runFIFO(vector<Process> plist) {
    int time = 0;

    cout << "时间\t" << "执行中\t" << "就绪队列\t" << endl;
    while (!plist.empty()) {
        cout << time << "~" << time + 1 << "\t";
        cout << plist.front().name << "\t";
        plist.front().runTime++;
        bool empty = true;
        for (int i = 1; i < plist.size(); i++) {
            if (plist[i].createTime <= time) {
                cout << plist[i].name << " ";
                empty = false;
            }
        }
        cout << (empty ? "<空>" : "");
        cout<<"\t";
        if (plist.front().runTime == plist.front().needTime) {
            cout << plist.front().name << "执行完成\t";
            plist.erase(plist.begin());
        }

        cout << "\t" << endl;
        time++;
    }
}

int main() {

//    vector<Process> plist = getProcessList();

    Process p1("p1", 0, 3);
    Process p2("p2", 2, 6);
    Process p3("p3", 4, 4);
    Process p4("p4", 6, 5);
    Process p5("p5", 8, 2);

    vector<Process> plist = {p1, p5, p3, p4, p2};
    sort(plist.begin(), plist.end(), MySort());
    runFIFO(plist);

    getchar();
    return 0;
}












//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//// 进程类
//class Process {
//public:
//    int processID;       // 进程ID
//    int arrivalTime;     // 到达时间
//    int burstTime;       // 服务时间
//    int waitingTime;    // 等待时间
//    int turnaroundTime; // 周转时间
//
//    Process(int processID, int arrivalTime, int burstTime)
//            : processID(processID),
//              arrivalTime(arrivalTime),
//              burstTime(burstTime),
//              waitingTime(0),
//              turnaroundTime(0) {}
//};
//
//// 自定义排序函数，按到达时间升序排序
//bool sortByArrivalTime(const Process& p1, const Process& p2) {
//    return p1.arrivalTime < p2.arrivalTime;
//}
//
//// FCFS调度算法
//void FCFS(std::vector<Process>& processes) {
//    // 按到达时间对进程进行排序
//    std::sort(processes.begin(), processes.end(), sortByArrivalTime);
//
//    int n = processes.size(); // 进程数
//    int currentTime = 0;     // 当前时间
//
//    for (int i = 0; i < n; i++) {
//        // 计算等待时间 = max(0, 当前时间 - 到达时间)
//        processes[i].waitingTime = std::max(0, currentTime - processes[i].arrivalTime);
//
//        // 计算周转时间 = 等待时间 + 服务时间
//        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
//
//        // 更新当前时间
//        currentTime += processes[i].burstTime;
//    }
//}
//
//int main() {
//    // 示例进程数据
//    std::vector<Process> processes = {
//            {1, 0, 6},
//            {2, 2, 4},
//            {3, 4, 7},
//            {4, 6, 3},
//            {5, 8, 5}
//    };
//
//    // 调用FCFS算法
//    FCFS(processes);
//
//    // 输出结果
//    std::cout << "进程ID\t到达时间\t服务时间\t等待时间\t周转时间" << std::endl;
//    for (const Process& process : processes) {
//        std::cout << process.processID << "\t" << process.arrivalTime << "\t\t" << process.burstTime
//                  << "\t\t" << process.waitingTime << "\t\t" << process.turnaroundTime << std::endl;
//    }
//
//    getchar();
//    return 0;
//}


/*
#include<iostream>
#include "vector"
#include "algorithm"
using namespace std;
// 定义进程结构体
struct Process {
    int id; // 进程ID
    int arriveTime; // 到达时间
    int burstTime; // 执行时间
};

int main() {
    int n; // 进程数
    cout << "请输入进程数：";
    cin >> n;

    // 输入每个进程的信息
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "请输入第" << i + 1 << "个进程的到达时间和执行时间：";
        cin >> processes[i].arriveTime >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    // 按照到达时间排序
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arriveTime < b.arriveTime;
    });

    // 模拟先来先服务进程调度算法
    int currentTime = 0; // 当前时间
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arriveTime) {
            currentTime = processes[i].arriveTime;
        }
        cout << "执行进程" << processes[i].id << "，开始时间：" << currentTime << "，执行时间：" << processes[i].burstTime << "，结束时间：" << currentTime + processes[i].burstTime << "。" << endl;
        currentTime += processes[i].burstTime;
    }

    getchar();
    return 0;
}
*/


