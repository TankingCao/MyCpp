#pragma once
#include<iostream>

using namespace std;

void print(int arr[], int len,int block,int hits) {

	cout << "\n--------------------------------------------------------" << endl;

	cout << "�������У�";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "�������: \t|" << block << endl;
	cout << "�ܳ���: \t|" << len << endl;
	cout << "���д���: \t|" << hits << endl;
	cout << "������: \t|" << 100.0 * hits / len << "%" << endl;
	cout << "ȱҳ��: \t|" << (100.0 * (len - hits)) / len << "%" << endl;

	cout << "--------------------------------------------------------" << endl;
}

//�ж�Ԫ���Ƿ������������
bool IsInArray(vector<int>v, int target) {
	for (int i : v) {
		if (target == i)
			return true;
	}
	return false;
}

//��ȡָ��Ԫ�ص�����
int index(vector<int>v, int target) {
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == target)
			return i;
	}
}