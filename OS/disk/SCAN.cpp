/**
 *  <h1 color="#10ac84">Created by ľɼ on ��2023/4/15/ 015�� ���� 04:28:58</h1>
 */

#include <iostream>
#include <algorithm>
#include "vector"
#include "print.h"

using namespace std;

vector<int> runSCAN(vector<int> arr, int start, bool);

void test01() {
    int start = 100;
    vector<int> arr = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    bool larger = true;//��ʾ�ȴ�С����ɨ��
    print(runSCAN(arr, start, larger));
}

int main() {

    test01();

    getchar();
    return 0;
}

/**
 * <h2 color="#10ac84">��ȡ����˳�������</h2>
 * */
vector<int> runSCAN(vector<int> arr, int start, bool larger) {
    arr.push_back(start);
    sort(arr.begin(), arr.end());

    //������ҵ�startֵ����������������ֳ�����
    int index;
    for (int i = 0; i < arr.size(); i++) {
        if (start == arr[i]) {
            index = i;
        }
    }

    vector<int> pre(arr.begin(), arr.begin() + index);
    vector<int> next(arr.begin() + index + 1, arr.end());

    //ǰ��һ������ķ���˳��һ���������
    reverse(pre.begin(), pre.end());

    //����larger�жϿ�ʼ�ƶ��ķ���Ȼ��˳����������
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