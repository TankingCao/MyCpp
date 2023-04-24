#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * FCFS�����㷨
 * */


struct Process {
    string name;
    int arrivalTime;
    int burstTime;
    int remainingTime; // ʣ������ʱ��
};

vector<Process> plist; // �����б�
int timeQuantum; // ʱ��Ƭ��С

// ��ȡ�����б�
void getProcessList() {
    int n;
    cout << "�������������";
    cin >> n;
    plist.resize(n);
    for (int i = 0; i < n; i++) {
        cout << "��������� " << i + 1 << " �����ơ�����ʱ���ִ��ʱ�䣺";
        cin >> plist[i].name >> plist[i].arrivalTime >> plist[i].burstTime;
        plist[i].remainingTime = plist[i].burstTime; // ��ʼʣ��ʱ�����ִ��ʱ��
    }
    cout << "������ʱ��Ƭ��С��";
    cin >> timeQuantum;
}

// ʱ��Ƭ��ת�����㷨
void run() {
    vector<Process> readyQueue; // ��������
    int currentTime = 0; // ��ǰʱ��

    while (!plist.empty() || !readyQueue.empty()) {
        // ������ʱ��С�ڵ��ڵ�ǰʱ��Ľ��̼����������
        for (int i = 0; i < plist.size(); i++) {
            if (plist[i].arrivalTime <= currentTime) {
                readyQueue.push_back(plist[i]);
                plist.erase(plist.begin() + i);
                i--;
            }
        }

        if (readyQueue.empty()) {
            // �����������Ϊ�գ���ʱ��ǰ������һ�����̵ĵ���ʱ��
            int nextArrivalTime = plist[0].arrivalTime;
            for (int i = 1; i < plist.size(); i++) {
                if (plist[i].arrivalTime > currentTime && plist[i].arrivalTime < nextArrivalTime) {
                    nextArrivalTime = plist[i].arrivalTime;
                }
            }
            currentTime = nextArrivalTime;
        } else {
            // �Ӿ�������ȡ����һ������ִ��
            Process currentProcess = readyQueue.front();
            readyQueue.erase(readyQueue.begin());

            int remainingTime = currentProcess.remainingTime;
            if (remainingTime <= timeQuantum) {
                // �������ʣ��ʱ��С�ڵ���ʱ��Ƭ��С�������ִ�����
                currentTime += remainingTime;
                cout << "���� " << currentProcess.name << " ��ʱ�� " << currentTime << " ִ�����" << endl;
            } else {
                // ����ִ��һ��ʱ��Ƭ��ʱ��
                currentTime += timeQuantum;
                cout << "���� " << currentProcess.name << " ��ʱ�� " << currentTime << " ִ����һ��ʱ��Ƭ" << endl;
                // ���½���ʣ��ʱ�䲢�Żؾ�������
                currentProcess.remainingTime -= timeQuantum;
                readyQueue.push_back(currentProcess);
            }
        }
        if (plist.empty() && readyQueue.empty()) {
            break;
        }
    }
}

int main() {
    getProcessList();
    run();

    cin.get();
    return 0;
}
