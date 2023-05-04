#include<iostream>
#include<vector>

using namespace std;

bool IsInArray(vector<int> v, int target);

void print(int arr[], int len, int block, int hits);

//执行FIFO算法
int FIFO(int arr[], int len, int block) {
    int hits = 0;
    bool IsHit;

    vector<int> list;

    for (int i = 0; i < len; i++) {
        IsHit = false;
        //在队列中，命中
        if (IsInArray(list, arr[i])) {
            hits++;
            IsHit = true;
        } else if (list.size() < block) {
            list.push_back(arr[i]);
        } else {    //没有空闲位置,出队后插入
            list.erase(list.begin());
            list.push_back(arr[i]);
        }
        cout << arr[i] << "->";
        for (int i = list.size() - 1; i >= 0; i--) {
            cout << "|" << list.at(i);
        }
        cout << (IsHit ? "  <命中>" : "") << endl;

    }
    return hits;
}

int main() {

    int arr[] = {5, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 5, 0, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int block = 3;//物理块数为3
    int hits = FIFO(arr, len, block);

    print(arr, len, block, hits);

    getchar();
    return 0;
}

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