#include<iostream>
#include<vector>

using namespace std;

bool IsInArray(vector<int> v, int target);

void print(int arr[], int len, int block, int hits);

//ִ��FIFO�㷨
int FIFO(int arr[], int len, int block) {
    int hits = 0;
    bool IsHit;

    vector<int> list;

    for (int i = 0; i < len; i++) {
        IsHit = false;
        //�ڶ����У�����
        if (IsInArray(list, arr[i])) {
            hits++;
            IsHit = true;
        } else if (list.size() < block) {
            list.push_back(arr[i]);
        } else {    //û�п���λ��,���Ӻ����
            list.erase(list.begin());
            list.push_back(arr[i]);
        }
        cout << arr[i] << "->";
        for (int i = list.size() - 1; i >= 0; i--) {
            cout << "|" << list.at(i);
        }
        cout << (IsHit ? "  <����>" : "") << endl;

    }
    return hits;
}

int main() {

    int arr[] = {5, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 5, 0, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int block = 3;//�������Ϊ3
    int hits = FIFO(arr, len, block);

    print(arr, len, block, hits);

    getchar();
    return 0;
}

void print(int arr[], int len, int block, int hits) {
    cout << "\n--------------------------------------------------------" << endl;
    cout << "ҳ�����˳��Ϊ��";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "�������: \t|" << block << endl;
    cout << "�����ʴ���: \t|" << len << endl;
    cout << "δ���д���: \t|" << len - hits << endl;
    cout << "������: \t|" << 100.0 * hits / len << "%" << endl;
    cout << "--------------------------------------------------------" << endl;
}

//�ж�Ԫ���Ƿ������������
bool IsInArray(vector<int> v, int target) {
    for (int i: v) {
        if (target == i)
            return true;
    }
    return false;
}