#include<iostream>
#include<vector>

using namespace std;

void print(int arr[], int len, int block, int hits);

bool IsInArray(vector<int> v, int target);

int index(vector<int> v, int target);

//ִ��LRU�㷨
int LRU(int arr[], int len, int block) {
    int hits = 0;
    bool IsHit;
    vector<int> list;

    for (int i = 0; i < len; i++) {
        IsHit = false;//�Ƿ�����
        //�ڶ����У�������������ŵ���β
        if (IsInArray(list, arr[i])) {
            hits++;
            IsHit = true;
            //��ɾ��
            list.erase(list.begin() + index(list, arr[i]));
            //�����
            list.push_back(arr[i]);
        } else if (list.size() < block) {    //���ڶ��������п���λ�ã�ֱ�Ӳ���
            list.push_back(arr[i]);
        } else {    //û�п���λ�ã�һ��Ԫ�س��Ӻ����
            list.erase(list.begin());
            list.push_back(arr[i]);
        }
        cout << arr[i] << "->";

        for (int i = list.size() - 1; i >= 0; i--) {
            cout << "|" << list.at(i);
        }
        cout << (IsHit ? "   <����>" : "") << endl;

    }
    return hits;
}

int main() {
    int arr[] = {4, 5, 5, 6, 3, 5, 4, 6, 8, 1, 1, 6, 2, 5, 6, 7, 0, 2, 8, 9};

    int len = sizeof(arr) / sizeof(arr[0]);
    int block = 3;//�������Ϊ3
    int hits = LRU(arr, len, block);

    print(arr, len, block, hits);

    getchar();
    return 0;
}

//��ӡ���
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

//��ȡָ��Ԫ�ص�����
int index(vector<int> v, int target) {
    for (int i = 0; i < v.size(); i++) {
        if (v.at(i) == target)
            return i;
    }
    return -1;
}