#include<iostream>
#include"print.h"
using namespace std;

int runFIFO(int start, int arr[], int len) {
    int sum = 0;
    for (int i = 0; i < len - 1; i++) {
        sum += abs(arr[i] - arr[i + 1]);
    }
    sum += abs(start - arr[0]);
    return sum;
}

void test01(){
    int start = 100;
    int arr[] = {55, 58, 39, 18, 90, 160, 150, 38, 184};
    int len1 = sizeof(arr) / sizeof(arr[0]);
    int length1 = runFIFO(start, arr, len1);
    printFIFO(arr, len1, length1);
}

void test02(){
    int start2 = 143;
    int arr2[] = {86, 147, 91, 177, 94, 150, 102, 175, 130};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    int length2 = runFIFO(start2, arr2, len2);
    printFIFO(arr2, len2, length2);
}

int main() {

    test01();

    test02();

    getchar();
    return 0;
}