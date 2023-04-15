#include<iostream>
#include"vector"
#include<algorithm>
#include"func.h"

using namespace std;

//ִ��LRU�㷨
int LRU(int arr[], int len, int block) {
	int hits = 0;
	bool IsHit;

	vector<int>list;

	for (int i = 0; i < len; i++) {
		IsHit = false;
		//�ڶ����У�������������ŵ���β
		if (IsInArray(list, arr[i])) {
			hits++;
			IsHit = true;
			//��ɾ��
			list.erase(list.begin()+index(list, arr[i]));
			//������
			list.push_back(arr[i]);
		}
		else if (list.size() < block) {	//���ٶ��������п���λ�ã�ֱ�Ӳ���
			list.push_back(arr[i]);
		}
		else {	//û�п���λ�ã�ȥ��ͷ��Ԫ�غ����
			list.erase(list.begin());
			list.push_back(arr[i]);
		}
		cout << arr[i] << "->";

		for (int i = list.size() - 1; i >= 0;i--) {
			cout << "|" << list.at(i);
		}
		cout << (IsHit ? "  <����>" : "") << endl;

	}
	return hits;
}

void test01() {
	int arr[] = { 5,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,5,0,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int block = 3;//��������Ϊ3

	int hits = LRU(arr, len, block);

	print(arr, len, block, hits);
}

int main() {

	test01();

    getchar();
	return 0;
}