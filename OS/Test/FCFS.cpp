#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

/*
 * FCFS�����㷨
 * */

//���������
class Process {
public:
    Process() = default;

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

//��ȡ���н��̲�����ʱ������
vector<Process> getProcessList() {
    vector<Process> pcb;
    int processNum;
    cout << "\n���뱻���ȵ�<���̵���Ŀ>��";
    cin >> processNum;
    for (int i = 0; i < processNum; i++) {
        Process p;
        cout << "����<������>��<����ʱ��>��<��Ҫ����ʱ��>:";
        cin >> p.name;
        cin >> p.createTime;
        cin >> p.needTime;
        pcb.push_back(p);
    }
    sort(pcb.begin(), pcb.end(), [](Process p1, Process p2) { return p1.createTime < p2.createTime; });
    return pcb;
}

void runFCFS(vector<Process> plist) {
    int time = 0;
    cout << "\nʱ��\t" << "ִ��\t" << "����\t" << endl;

    while (!plist.empty()) {
        cout << time << "~" << time + 1 << "\t";
        plist[0].runTime++;
        //������ɵĽ������ּ���"��"
        cout << ((plist[0].runTime == plist[0].needTime) ? plist[0].name + "��" : plist[0].name) << "\t";
        bool empty = true;
        for (int i = 1; i < plist.size(); i++) {
            if (plist[i].createTime <= time) {
                cout << plist[i].name << " ";
                empty = false;
            }
        }
        cout << (empty ? "<��>" : "");
        cout << "\t";
        //�������ʱ������
        if (plist[0].runTime == plist[0].needTime) {
            plist.erase(plist.begin());
        }
        cout << "\t" << endl;
        time++;
    }
}

int main() {

    Process p1("A", 0, 3);
    Process p2("B", 2, 6);
    Process p3("C", 4, 4);
    Process p4("D", 6, 5);
    Process p5("E", 8, 2);

    vector<Process> plist = {p1, p5, p3, p4, p2};

    runFCFS(getProcessList());

    system("pause");
    return 0;
}