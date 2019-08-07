#include <iostream>
#include <vector>
using namespace std;

// 寻找最后一个0的位置
int search1(const vector<bool>& arr) {
    int length = arr.size();
    int begin = 0, end = length - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (arr[mid]) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return end;  // 返回-1表示找不到
}

// 寻找第一个1的位置
int search2(const vector<bool>& arr) {
    int length = arr.size();
    int begin = 0, end = length - 1;
    while (begin <= end) {
        int mid = (begin + end) / 2;
        if (arr[mid]) {
            end = mid - 1;
        } else {
            begin = mid + 1;
        }
    }
    return begin;  // 返回length表示找不到
}

int main() {
    // arr数组必须0在前，1在后
    vector<bool> arr1 = {0, 0, 0, 0, 0, 1, 1, 1};
    vector<bool> arr2 = {0, 0, 0, 0, 0};
    vector<bool> arr3 = {1, 1, 1, 1};

    cout << search1(arr1) << endl;  // 4
    cout << search2(arr1) << endl;  // 5
    cout << search1(arr2) << endl;  // 4
    cout << search2(arr2) << endl;  // 5
    cout << search1(arr3) << endl;  // -1
    cout << search2(arr3) << endl;  // 0

    return 0;
}