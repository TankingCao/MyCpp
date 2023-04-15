/**
 * <h1 color="#10ac84">Created by 木杉 on 「2023/4/15/ 015」</h1>
 * */

#ifndef MYCPP_PRINT_H
#define MYCPP_PRINT_H

#include<iostream>
#include "vector"
using namespace std;

/**
 * <h1 color="#10ac84">
 * len:数组的长度<br>
 * length:寻道的长度</h1>
 * */
void printFIFO(int arr[], int len, int length) {
    //先来先服务，所以寻道顺序就是请求服务数组的顺序
    cout << "--------------------------------------------------------" << endl;
    cout << "寻道顺序：";
    for (int i = 0; i < len; i++) {
        if (i != len - 1)
            cout << arr[i] << "->";
        else
            cout << arr[i] << endl;
    }
    cout << "寻道总长度：" << length << endl;
    cout << "平均寻道长度：" << length * 1.0 / len << endl;
    cout << "--------------------------------------------------------" << endl << endl;
}

void print(vector<int> v) {
    int sum = 0;
    for (int i = 0; i < v.size() - 1; i++) {
        sum += abs(v.at(i) - v.at(i + 1));
    }
    cout << "-------------------------------------------------------------" << endl;
    cout << "寻道顺序:\t|";
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1)
            cout << v.at(i) << "->";
        else
            cout << v.at(i) << endl;
    }
    cout << "寻道总长度:\t|" << sum << endl;
    cout << "平均寻道长度:\t|" << sum * 1.0 / (int)(v.size()-1) << endl;
    cout << "-------------------------------------------------------------" << endl << endl;
}

#endif //MYCPP_PRINT_H
