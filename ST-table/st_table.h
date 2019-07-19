// ST表
// 用来计算区间最值，O(nlogn)预处理，O(1)查询最值
// 洛谷P3865

#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int SIZE = 100000;
const int K = 17;
int MAX[SIZE][K];  // K=int(log2(SIZE))+1

// 查找区间arr[left~right]内的最大值
inline int query(int left, int right) {
    int k = int(log2(right - left + 1));
    return max(MAX[left][k], MAX[right - (1 << k) + 1][k]);
}

// 快读
inline int readInt() {
    int num = 0, sign = 1;
    int ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')
            sign = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        num = num * 10 + ch - '0';
        ch = getchar();
    }
    return num * sign;
}

int main() {
    int N, M;
    N = readInt();
    M = readInt();
    for (int i = 0; i < N; ++i) {
        MAX[i][0] = readInt();
    }

    // 动态规划
    // 动态转移方程：MAX[i][j] = max(MAX[i][j-1], MAX[i+2^(j-1)][j-1])
    int k = int(log2(N)) + 1;
    for (int j = 1; j < k; ++j) {
        for (int i = 0; i + (1 << j) - 1 < N; ++i) {
            MAX[i][j] = max(MAX[i][j - 1], MAX[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < M; ++i) {
        int L, R;
        L = readInt();
        R = readInt();
        int result = query(L - 1, R - 1);
        printf("%d\n", result);
    }

    return 0;
}