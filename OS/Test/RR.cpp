#include <iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

/*
 * 时间片轮转调度算法
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

    string name;//进程名称
    int createTime = 0;//创建时间
    int needTime = 0;//需要运行的时间
    int runTime = 0;//已经运行的时间
    int state = 1;//1-运行时间未满，0-运行时间已满
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

//运行时间片轮转调度算法
void runRR(vector<Process> plist) {
    int time = 0;//记录时刻
    vector<Process> ready;//就绪队列
    Process p;//记录未运行完的进程
    p.state = 0;

    cout << "\n时间\t" << "执行\t" << "就绪\t" << endl;

    do {
        cout << time << "~" << time + 1 << "\t";
        //先插入新的进程
        if (!plist.empty()) {
            for (int i = 0; i < plist.size(); ++i) {
                if (plist[i].createTime <= time) {
                    ready.push_back(plist[i]);
                    plist.erase(plist.begin() + i);
                }
            }
        }

        //插入上次未运行完的进程
        if (p.state == 1) {
            ready.push_back(p);
        }

        //从就绪队列取出第一个进程运行,运行完成后判断运行时间是否满了
        ready[0].runTime++;
        if (ready[0].runTime == ready[0].needTime) {
            ready[0].state = 0;
        }
        //如果运行完成就加上三角形
        cout << (ready[0].state == 1 ? ready[0].name : ready[0].name + "△") << "\t";
        p = ready[0];
        ready.erase(ready.begin());

        //打印就绪队列进程，没有就打印空
        if (ready.empty()) {
            cout << "<空>";
        }
        for (Process i: ready) {
            cout << i.name << " ";
        }

        time++;
        cout << endl;

    } while (!ready.empty() || !plist.empty() || p.state == 1);//当没有进程需要运行时退出

}

int main() {

/*    Process p1("A", 0, 3);
    Process p2("B", 2, 6);
    Process p3("C", 4, 4);
    Process p4("D", 6, 5);
    Process p5("E", 8, 2);

    vector<Process> plist = {p1, p5, p3, p4, p2};*/

    runRR(getProcessList());

    system("pause");
    return 0;
}