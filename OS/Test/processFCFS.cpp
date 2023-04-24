#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * FCFS调度算法
 * */

//定义进程类
class Process {
public:
    Process() = default;

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

class MySort {
public:
    bool operator()(Process p1, Process p2) {
        return p1.createTime < p2.createTime;
    }
};

//获取所有进程并根据时间排序
vector<Process> getProcessList() {
    vector<Process> pcb;
    int processNum;
    cout << "\n输入被调度的<进程的数目>：";
    cin >> processNum;
    for (int i = 0; i < processNum; i++) {
        Process p;
        cout << "输入<进程名>:";
        cin >> p.name;
        cout << "分别输入<创建时间>、<需要运行时间>:";
        cin >> p.createTime;
        cin >> p.needTime;
        pcb.push_back(p);
    }
    sort(pcb.begin(), pcb.end(), MySort());
    return pcb;
}

void runFIFO(vector<Process> plist) {
    int time = 0;
    cout << "\n时间\t" << "执行\t" << "就绪\t" << endl;

    while (!plist.empty()) {
        cout << time << "~" << time + 1 << "\t";
        plist[0].runTime++;
        //运行完成的进程名字加上"△"
        cout << ((plist[0].runTime == plist[0].needTime) ? plist[0].name + "△" : plist[0].name) << "\t";
        bool empty = true;
        for (int i = 1; i < plist.size(); i++) {
            if (plist[i].createTime <= time) {
                cout << plist[i].name << " ";
                empty = false;
            }
        }
        cout << (empty ? "<空>" : "");
        cout << "\t";
        //如果运行时间满了
        if (plist[0].runTime == plist[0].needTime) {
            plist.erase(plist.begin());
        }
        cout << "\t" << endl;
        time++;
    }
}

int main() {
    vector<Process> plist = getProcessList();
    runFIFO(plist);

    system("pause");
    return 0;
}
