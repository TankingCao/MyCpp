/**
 * <h1 color="#10ac84">Created by ľɼ on ��2023/4/15/ 015��</h1>
 * */

#ifndef MYCPP_PRINT_H
#define MYCPP_PRINT_H

#include<iostream>
#include "vector"
using namespace std;

/**
 * <h1 color="#10ac84">
 * len:����ĳ���<br>
 * length:Ѱ���ĳ���</h1>
 * */
void printFIFO(int arr[], int len, int length) {
    //�����ȷ�������Ѱ��˳�����������������˳��
    cout << "--------------------------------------------------------" << endl;
    cout << "Ѱ��˳��";
    for (int i = 0; i < len; i++) {
        if (i != len - 1)
            cout << arr[i] << "->";
        else
            cout << arr[i] << endl;
    }
    cout << "Ѱ���ܳ��ȣ�" << length << endl;
    cout << "ƽ��Ѱ�����ȣ�" << length * 1.0 / len << endl;
    cout << "--------------------------------------------------------" << endl << endl;
}

void print(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        sum += abs(v.at(i) - v.at(i + 1));
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "Ѱ��˳��:\t|";
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1)
            cout << v.at(i) << "->";
        else
            cout << v.at(i) << endl;
    }
    cout << "Ѱ���ܳ���:\t|" << sum << endl;
    cout << "ƽ��Ѱ������:\t|" << sum * 1.0 / (int)(v.size()-1) << endl;
    cout << "-------------------------------------------------------------" << endl << endl;
}

#endif //MYCPP_PRINT_H
