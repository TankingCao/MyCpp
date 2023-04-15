/**
 *  <h1 color="#10ac84">Created by 木杉 on 「2023/4/15/ 015」 上午 11:28:06</h1>
 */

#include <iostream>
#include "vector"
#include "print.h"
using namespace std;

/**
 * <h1 color="#10ac84">函数声明</h1>
 * */
int findNearestNumber(vector<int> arr, int target);
vector<int> runSSTF(int start, vector<int> arr);

void test01(){
    int start = 100;
    vector<int> arr = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    print(runSSTF(start, arr));
}

int main() {

    test01();

    getchar();
    return 0;
}
/**
 * <h1 color="#10ac84">求寻道顺序</h1>
 * */
vector<int> runSSTF(int start, vector<int> arr) {
    vector<int> v;
    v.push_back(start);
    int index;
    int j = 0;
    while (!arr.empty()) {
        index = findNearestNumber(arr, v.at(j));
        v.push_back(arr.at(index));
        arr.erase(arr.begin() + index);
        j++;
    }
    return v;
}
/**
 * <h1 color="#10ac84">从数组中寻找最近的数的索引</h1>
 * */
int findNearestNumber(vector<int> arr, int target) {
    int index = 0;
    int near = abs(target - arr.at(index));
    for (int i = 1; i < arr.size(); i++) {
        if (abs(arr.at(i) - target) < near) {
            near = abs(arr.at(i) - target);
            index = i;
        }
    }
    return index;
}