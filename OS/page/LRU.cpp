#include<iostream>
#include"vector"
#include"func.h"

using namespace std;

//执行LRU算法
int LRU(int arr[], int len, int block) {
	int hits = 0;
	bool IsHit;

	vector<int>list;

	for (int i = 0; i < len; i++) {
		IsHit = false;
		//在队列中，命中则将这个数放到队尾
		if (IsInArray(list, arr[i])) {
			hits++;
			IsHit = true;
			//先删除
			list.erase(list.begin()+index(list, arr[i]));
			//再添加
			list.push_back(arr[i]);
		}
		else if (list.size() < block) {	//不再队列中且有空闲位置，直接插入
			list.push_back(arr[i]);
		}
		else {	//没有空闲位置，去除头部元素后插入
			list.erase(list.begin());
			list.push_back(arr[i]);
		}
		cout << arr[i] << "->";

		for (int i = list.size() - 1; i >= 0;i--) {
			cout << "|" << list.at(i);
		}
		cout << (IsHit ? "  <命中>" : "") << endl;

	}
	return hits;
}

void test01() {
	int arr[] = { 5,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,5,0,1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int block = 3;//物理块数为3

	int hits = LRU(arr, len, block);

	print(arr, len, block, hits);
}

int main() {

	test01();

    getchar();
	return 0;
}