#include <iostream>
#include<vector>
#include <algorithm>

using namespace std;

//���������
class Process {
public:
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

    cout << "������ȵĽ�����Ŀ:";
    cin >> num;
    for (int i = 0; i < num; ++i) {
        Process p;
        cout << "�����������:";
        cin >> p.name;
        cout << "�ֱ�������̵Ĵ���ʱ�䡢��Ҫ���е�ʱ��:";
        cin >> p.createTime;
        cin >> p.needTime;
        plist.push_back(p);
    }
    //������ʱ������
    sort(plist.begin(), plist.end(), [](Process p1, Process p2) { return p1.createTime < p2.createTime; });

    return plist;
}

//��ӡ����
void print(vector<Process> vector) {
    for (auto i: vector) {
        cout << i.name << " ";
    }
}

//����ʱ��Ƭ��ת�����㷨
void run(vector<Process> plist) {
    int time = 0;//��¼ʱ��
    vector<Process> ready;//��������
    Process p;//��¼δ������Ľ���
    p.state = 0;

    cout << "ʱ��\t" << "ִ��\t" << "����\t" << endl;

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

    vector<Process> plist = getProcessList();
    sort(plist.begin(), plist.end(), [](Process p1, Process p2) { return p1.createTime < p2.createTime; });
    run(plist);


    system("pause");
    return 0;
}