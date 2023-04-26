/**
 *  <h1 color="#10ac84">Created by ľɼ on ��2023/4/26/ 026�� ���� 09:06:35</h1>
 */

/**
 * <h1 color="#10ac84">����ռʽ��������ȼ����ȵ����㷨</h1>
 * */

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

//���������
class Process {
public:
    Process() = default;

    Process(string n, int ct, int nt, int p) {
        name = n;
        createTime = ct;
        needTime = nt;
        priority = p;
    }

    string name;//������
    int createTime = 0;//����ʱ��
    int needTime = 0;//��Ҫ���е�ʱ��
    int runTime = 0;//�Ѿ����е�ʱ��
    int priority = 0;//����������
};

//��ȡ��������н��̷��ؽ����б�
vector<Process> getProcessList() {
    int num = 0;
    vector<Process> plist;

    cout << "������Ҫ���ȵ�<������Ŀ>:";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        Process p;
        cout << "�ֱ�����<��������>��<����ʱ��>��<����ʱ��>:";
        cin >> p.name;
        cin >> p.createTime;
        cin >> p.needTime;
        plist.push_back(p);
    }
    //������ʱ������
    sort(plist.begin(), plist.end(), [](Process p1, Process p2) { return p1.createTime < p2.createTime; });

    return plist;
}

void runFPF(vector<Process> plist) {
    int time = 0;//��¼���е�ʱ��
    vector<Process> ready;//��������
    Process p;//��¼δ������Ľ���

    cout << "\nʱ��\t" << "ִ��\t" << "����\t" << endl;
    do {
        cout << time << "~" << time + 1 << "\t";
        //���������Ľ���
        for (int i = 0; i < plist.size(); i++) {
            if (plist[i].createTime <= time) {
                ready.push_back(plist[i]);
                plist.erase(plist.begin() + i);
            }
        }

        //�Ծ��������еĽ��̰������ȼ���������Խ�����ȼ�Խ�ͣ���������
        sort(ready.begin(), ready.end(), [](Process p1, Process p2) {
            return p1.priority < p2.priority;
        });

        //�����ϴ�δ������ɵĽ���
        if (p.runTime != p.needTime) {
            ready.insert(ready.begin()+0, p);
        }

        //ȡ�����������еĵ�һ�����̣����ȼ���ߵĽ��̣�����
        ready[0].runTime++;

        //���������ɴ�ӡʱ���ϡ�
        cout << (ready[0].runTime == ready[0].needTime ? ready[0].name + "��" : ready[0].name) << "\t";
        p = ready[0];
        ready.erase(ready.begin());

        //��ӡ�������н��̣�û�д�ӡ��
        if (ready.empty()) {
            cout << "<��>";
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