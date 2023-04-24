#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

//���������
class Process {
public:
    Process() {};

    Process(string n, int ct, int nt) {
        name = n;
        createTime = ct;
        needTime = nt;
    }

    string name;//������
    int createTime = 0;//����ʱ��
    int needTime = 0;//��Ҫ���е�ʱ��
    int runTime = 0;//�Ѿ����е�ʱ��
};

//���ݴ���ʱ������
class MySort {
public:
    bool operator()(Process p1, Process p2) {
        return p1.createTime < p2.createTime;
    }
};


//��ȡ���н���
vector<Process> getProcessList() {
    vector<Process> pcb;
    int processNum;
    cout << "\n���뱻���ȵĽ��̵���Ŀ��";
    cin >> processNum;
    for (int i = 0; i < processNum; i++) {
        Process p;
        cout << "\n���̺�No." << i + 1 << ":";
        cout << "���������:";
        cin >> p.name;
        cout << "�ֱ����� ����ʱ�䡢��Ҫ����ʱ��:";
        cin >> p.createTime;
        cin >> p.needTime;
        pcb.push_back(p);
    }
    sort(pcb.begin(), pcb.end(), MySort());
    return pcb;
}

void runFIFO(vector<Process> plist) {
    int time = 0;

    cout << "ʱ��\t" << "ִ����\t" << "��������\t" << endl;
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
        cout << (empty ? "<��>" : "");
        cout<<"\t";
        if (plist.front().runTime == plist.front().needTime) {
            cout << plist.front().name << "ִ�����\t";
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
//// ������
//class Process {
//public:
//    int processID;       // ����ID
//    int arrivalTime;     // ����ʱ��
//    int burstTime;       // ����ʱ��
//    int waitingTime;    // �ȴ�ʱ��
//    int turnaroundTime; // ��תʱ��
//
//    Process(int processID, int arrivalTime, int burstTime)
//            : processID(processID),
//              arrivalTime(arrivalTime),
//              burstTime(burstTime),
//              waitingTime(0),
//              turnaroundTime(0) {}
//};
//
//// �Զ�����������������ʱ����������
//bool sortByArrivalTime(const Process& p1, const Process& p2) {
//    return p1.arrivalTime < p2.arrivalTime;
//}
//
//// FCFS�����㷨
//void FCFS(std::vector<Process>& processes) {
//    // ������ʱ��Խ��̽�������
//    std::sort(processes.begin(), processes.end(), sortByArrivalTime);
//
//    int n = processes.size(); // ������
//    int currentTime = 0;     // ��ǰʱ��
//
//    for (int i = 0; i < n; i++) {
//        // ����ȴ�ʱ�� = max(0, ��ǰʱ�� - ����ʱ��)
//        processes[i].waitingTime = std::max(0, currentTime - processes[i].arrivalTime);
//
//        // ������תʱ�� = �ȴ�ʱ�� + ����ʱ��
//        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
//
//        // ���µ�ǰʱ��
//        currentTime += processes[i].burstTime;
//    }
//}
//
//int main() {
//    // ʾ����������
//    std::vector<Process> processes = {
//            {1, 0, 6},
//            {2, 2, 4},
//            {3, 4, 7},
//            {4, 6, 3},
//            {5, 8, 5}
//    };
//
//    // ����FCFS�㷨
//    FCFS(processes);
//
//    // ������
//    std::cout << "����ID\t����ʱ��\t����ʱ��\t�ȴ�ʱ��\t��תʱ��" << std::endl;
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
// ������̽ṹ��
struct Process {
    int id; // ����ID
    int arriveTime; // ����ʱ��
    int burstTime; // ִ��ʱ��
};

int main() {
    int n; // ������
    cout << "�������������";
    cin >> n;

    // ����ÿ�����̵���Ϣ
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "�������" << i + 1 << "�����̵ĵ���ʱ���ִ��ʱ�䣺";
        cin >> processes[i].arriveTime >> processes[i].burstTime;
        processes[i].id = i + 1;
    }

    // ���յ���ʱ������
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arriveTime < b.arriveTime;
    });

    // ģ�������ȷ�����̵����㷨
    int currentTime = 0; // ��ǰʱ��
    for (int i = 0; i < n; i++) {
        if (currentTime < processes[i].arriveTime) {
            currentTime = processes[i].arriveTime;
        }
        cout << "ִ�н���" << processes[i].id << "����ʼʱ�䣺" << currentTime << "��ִ��ʱ�䣺" << processes[i].burstTime << "������ʱ�䣺" << currentTime + processes[i].burstTime << "��" << endl;
        currentTime += processes[i].burstTime;
    }

    getchar();
    return 0;
}
*/


