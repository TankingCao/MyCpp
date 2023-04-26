/**
 *  <h1 color="#10ac84">Created by 木杉 on 「2023/4/26/ 026」 下午 09:06:35</h1>
 */

/**
 * <h1 color="#10ac84">非抢占式的最高优先级优先调度算法</h1>
 * */

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

//定义进程类
class Process {
public:
    Process() = default;

    Process(string n, int ct, int nt, int p) {
        name = n;
        createTime = ct;
        needTime = nt;
        priority = p;
    }

    string name;//进程名
    int createTime = 0;//创建时间
    int needTime = 0;//需要运行的时间
    int runTime = 0;//已经运行的时间
    int priority = 0;//进程优先数
};

//获取输入的所有进程返回进程列表
vector<Process> getProcessList() {
    int num = 0;
    vector<Process> plist;

    cout << "输入需要调度的<进程数目>:";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        Process p;
        cout << "分别输入<进程名称>、<创建时间>、<运行时间>:";
        cin >> p.name;
        cin >> p.createTime;
        cin >> p.needTime;
        plist.push_back(p);
    }
    //按创建时间排序
    sort(plist.begin(), plist.end(), [](Process p1, Process p2) { return p1.createTime < p2.createTime; });

    return plist;
}

void runFPF(vector<Process> plist) {
    int time = 0;//记录运行的时刻
    vector<Process> ready;//就绪队列
    Process p;//记录未运行完的进程

    cout << "\n时间\t" << "执行\t" << "就绪\t" << endl;
    do {
        cout << time << "~" << time + 1 << "\t";
        //插入新来的进程
        for (int i = 0; i < plist.size(); i++) {
            if (plist[i].createTime <= time) {
                ready.push_back(plist[i]);
                plist.erase(plist.begin() + i);
            }
        }

        //对就绪队列中的进程按照优先级（优先数越大优先级越低）进行排序
        sort(ready.begin(), ready.end(), [](Process p1, Process p2) {
            return p1.priority < p2.priority;
        });

        //插入上次未运行完成的进程
        if (p.runTime != p.needTime) {
            ready.insert(ready.begin()+0, p);
        }

        //取出就绪队列中的第一个进程（优先级最高的进程）运行
        ready[0].runTime++;

        //如果运行完成打印时加上△
        cout << (ready[0].runTime == ready[0].needTime ? ready[0].name + "△" : ready[0].name) << "\t";
        p = ready[0];
        ready.erase(ready.begin());

        //打印就绪队列进程，没有打印空
        if (ready.empty()) {
            cout << "<空>";
        }
        for (Process i: ready) {
            cout << i.name << " ";
        }

        time++;
        cout << endl;

    } while (!ready.empty() || !plist.empty() || p.runTime != p.needTime);

}

int main() {

    vector<Process> plist = {
            {"p1", 0, 3, 3},
            {"p2", 2, 6, 5},
            {"p3", 4, 4, 1},
            {"p4", 6, 5, 2},
            {"p5", 8, 2, 4}
    };

    runFPF(plist);

    getchar();
    return 0;
}