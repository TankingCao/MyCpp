/**
 *  <h1 color="#10ac84">Created by ľɼ on ��2023/4/24/ 024�� ���� 03:52:39</h1>
 */

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

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
    int priority = 0;//�������������˴���������Խ�����ȼ�Խ��
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
    return pcb;
}

void runFPF(vector<Process> plist){
    int time = 0;//��¼���е�ʱ��
    vector<Process>ready;//��������

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