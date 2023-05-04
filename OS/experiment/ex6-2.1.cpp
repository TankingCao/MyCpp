#include<iostream>
#include<vector>

using namespace std;

void print(int arr[], int len, int block, int hits);

bool IsInArray(vector<int> v, int target);

int index(vector<int> v, int target);

//执行LRU算法
int LRU(int arr[], int len, int block) {
    int hits = 0;
    bool IsHit;
    vector<int> list;

    for (int i = 0; i < len; i++) {
        IsHit = false;//是否命中
        //在队列中，命中则将这个数放到队尾
        if (IsInArray(list, arr[i])) {
            hits++;
            IsHit = true;
            //先删除
            list.erase(list.begin() + index(list, arr[i]));
            //再添加
            list.push_back(arr[i]);
        } else if (list.size() < block) {    //不在队列中且有空闲位置，直接插入
            list.push_back(arr[i]);
        } else {    //没有空闲位置，一个元素出队后插入
            list.erase(list.begin());
            list.push_back(arr[i]);
        }
        cout << arr[i] << "->";

        for (int i = list.size() - 1; i >= 0; i--) {
            cout << "|" << list.at(i);
        }
        cout << (IsHit ? "   <命中>" : "") << endl;

    }
    return hits;
}

int main() {
    int arr[] = {4, 5, 5, 6, 3, 5, 4, 6, 8, 1, 1, 6, 2, 5, 6, 7, 0, 2, 8, 9};

    int len = sizeof(arr) / sizeof(arr[0]);
    int block = 3;//物理块数为3
    int hits = LRU(arr, len, block);

    print(arr, len, block, hits);

    getchar();
    return 0;
}

//打印结果
void print(int arr[], int len, int block, int hits) {
    cout << "\n--------------------------------------------------------" << endl;
    cout << "页面访问顺序为：";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "物理块数: \t|" << block << endl;
    cout << "共访问次数: \t|" << len << endl;
    cout << "未命中次数: \t|" << len - hits << endl;
    cout << "命中率: \t|" << 100.0 * hits / len << "%" << endl;
    cout << "--------------------------------------------------------" << endl;
}

//判断元素是否存在于数组中
bool IsInArray(vector<int> v, int target) {
    for (int i: v) {
        if (target == i)
            return true;
    }
    return false;
}

//获取指定元素的索引
int index(vector<int> v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == target)
            return i;
    }
    return -1;
}