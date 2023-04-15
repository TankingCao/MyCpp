//#include<iostream>
//
//using namespace std;
//
//int binarySearch(int arr[], int len, int target) {
//	int i = 0;
//	int j = len - 1;
//	while (i <= j) {
//		int m = (i + j) / 2;
//		if (target < arr[m]) {
//			j = m - 1;
//		}
//		else if (arr[m] < target) {
//			i = m + 1;
//		}
//		else {
//			return m;
//		}
//	}
//	return -1;
//}
//
//int main() {
//
//	int arr[10];
//	for (int i = 0; i < 10; i++) {
//		arr[i] = i;
//	}
//
//	int len = sizeof(arr) / sizeof(arr[0]);
//
//	for (int i = 0; i < len; i++) {
//		cout << binarySearch(arr, len, i) << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}