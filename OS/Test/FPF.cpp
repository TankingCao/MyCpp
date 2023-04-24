/**
 *  <h1 color="#10ac84">Created by 木杉 on 「2023/4/24/ 024」 下午 03:52:39</h1>
 */

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

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
    int priority = 0;//进程优先数，此处是优先数越高优先级越高
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
    return pcb;
}

void runFPF(vector<Process> plist){
    int time = 0;//记录运行的时刻
    vector<Process>ready;//就绪队列

    for (int i = 0; i < plist.size(); ++i) {
        if (plist[i].createTime <= time) {
            ready.push_back(plist[i]);

        }
    }




}

int main() {

    Process p1("p1", 0, 3);
    Process p2("p2", 2, 6);
    Process p3("p3", 4, 4);
    Process p4("p4", 6, 5);
    Process p5("p5", 8, 2);

    vector<Process> plist = {p1, p5, p3, p4, p2};

    getchar();
    return 0;
}