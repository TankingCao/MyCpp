#include <iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

/*
 * ʱ��Ƭ��ת�����㷨
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

    string name;//��������
    int createTime = 0;//����ʱ��
    int needTime = 0;//��Ҫ���е�ʱ��
    int runTime = 0;//�Ѿ����е�ʱ��
    int state = 1;//1-����ʱ��δ����0-����ʱ������
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

//����ʱ��Ƭ��ת�����㷨
void runRR(vector<Process> plist) {
    int time = 0;//��¼ʱ��
    vector<Process> ready;//��������
    Process p;//��¼δ������Ľ���
    p.state = 0;

    cout << "\nʱ��\t" << "ִ��\t" << "����\t" << endl;

    do {
        cout << time << "~" << time + 1 << "\t";
        //�Ȳ����µĽ���
        if (!plist.empty()) {
            for (int i = 0; i < plist.size(); ++i) {
                if (plist[i].createTime <= time) {
                    ready.push_back(plist[i]);
                    plist.erase(plist.begin() + i);
                }
            }
        }

        //�����ϴ�δ������Ľ���
        if (p.state == 1) {
            ready.push_back(p);
        }

        //�Ӿ�������ȡ����һ����������,������ɺ��ж�����ʱ���Ƿ�����
        ready[0].runTime++;
        if (ready[0].runTime == ready[0].needTime) {
            ready[0].state = 0;
        }
        //���������ɾͼ���������
        cout << (ready[0].state == 1 ? ready[0].name : ready[0].name + "��") << "\t";
        p = ready[0];
        ready.erase(ready.begin());

        //��ӡ�������н��̣�û�оʹ�ӡ��
        if (ready.empty()) {
            cout << "<��>";
        }
        for (Process i: ready) {
            cout << i.name << " ";
        }

        time++;
        cout << endl;

    } while (!ready.empty() || !plist.empty() || p.state == 1);//��û�н�����Ҫ����ʱ�˳�

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