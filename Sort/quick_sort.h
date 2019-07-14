// 快速排序
// 洛谷P1177

#include <iostream>
using namespace std;

int arr[100000];

void quick_sort(int begin, int end) {
    if (begin >= end)
        return;
    int pivot = arr[(begin + end) >> 1];
    int left = begin, right = end;
    while (left <= right) {
        while (arr[left] < pivot)
            ++left;
        while (arr[right] > pivot)
            --right;
        if (left <= right) {
            swap(arr[left], arr[right]);
            ++left, --right;
        }
    }
    quick_sort(begin, right);
    quick_sort(left, end);
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    quick_sort(0, N - 1);

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}