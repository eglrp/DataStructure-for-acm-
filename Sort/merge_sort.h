// 归并排序
// 洛谷P1177

#include <iostream>
using namespace std;

int arr[100000];
int temp[100000];

void merge_sort(int begin, int end) {
    if (begin >= end)
        return;
    int mid = (begin + end) >> 1;
    merge_sort(begin, mid);
    merge_sort(mid + 1, end);
    int j1 = begin, j2 = mid + 1;
    for (int i = begin; i <= end; ++i) {
        if (j2 > end || (j1 <= mid && arr[j1] < arr[j2])) {
            temp[i] = arr[j1++];
        } else {
            temp[i] = arr[j2++];
        }
    }
    for (int i = begin; i <= end; ++i) {
        arr[i] = temp[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    merge_sort(0, N - 1);

    for (int i = 0; i < N; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;

    return 0;
}