/**
 *  <h1 color="#10ac84">Created by 木杉 on 「2023/4/15/ 015」 下午 05:42:15</h1>
 */

#include <iostream>
#include <algorithm>
#include "vector"
#include "print.h"

using namespace std;

vector<int> runCSCAN(vector<int> arr, int start, bool);

void test01() {
    int start = 100;
    vector<int> arr = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    bool larger = true;//表示先从小到大扫描
    print(runCSCAN(arr, start, larger));
}

void myPrint(vector<int> v) {
    for (int i: v) {
        cout << i << endl;
    }
}

int main() {

    test01();

    getchar();
    return 0;
}

/**
 * <h2 color="#10ac84">获取访问顺序的数组</h2>
 * */
vector<int> runCSCAN(vector<int> arr, int start, bool larger) {
    arr.push_back(start);
    sort(arr.begin(), arr.end());

    //排序后找到start值的索引，并将数组分成两半
    int index;
    for (int i = 0; i < arr.size(); i++) {
        if (start == arr[i]) {
            index = i;
        }
    }

    vector<int> pre(arr.begin(), arr.begin() + index);
    vector<int> next(arr.begin() + index + 1, arr.end());
    //如果是从大到小就要逆序
    if (!larger) {
        reverse(pre.begin(), pre.end());
        reverse(next.begin(), next.end());
    }

    //根据larger判断开始移动的方向，然后按顺序连接数组
    if (larger) {
        next.insert(next.end(), pre.begin(), pre.end());
        next.insert(next.begin(), start);
        return next;
    } else {
        pre.insert(pre.end(), next.begin(), next.end());
        pre.insert(pre.begin(), start);
        return pre;
    }

}