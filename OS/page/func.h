#pragma once
#include<iostream>

using namespace std;

void print(int arr[], int len,int block,int hits) {

	cout << "\n--------------------------------------------------------" << endl;

	cout << "访问序列：";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "物理块数: \t|" << block << endl;
	cout << "总长度: \t|" << len << endl;
	cout << "命中次数: \t|" << hits << endl;
	cout << "命中率: \t|" << 100.0 * hits / len << "%" << endl;
	cout << "缺页率: \t|" << (100.0 * (len - hits)) / len << "%" << endl;

	cout << "--------------------------------------------------------" << endl;
}

//判断元素是否存在于数组中
bool IsInArray(vector<int>v, int target) {
	for (int i : v) {
		if (target == i)
			return true;
	}
	return false;
}

//获取指定元素的索引
int index(vector<int>v, int target) {
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) == target)
			return i;
	}
}