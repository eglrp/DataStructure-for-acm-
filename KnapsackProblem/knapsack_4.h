// 多重背包问题（二进制优化）
// AcWing P5

#include <iostream>
using namespace std;

const int SIZE = 1000 * 12;
int weights[SIZE];
int values[SIZE];
int dp[2001];
int realN;
int N, W;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> W;
    realN = 0;
    for (int i = 0; i < N; ++i) {
        int weight, value, count;
        cin >> weight >> value >> count;
        for (int j = 1; count >= j; count -= j, j <<= 1) {
            weights[realN] = weight * j;
            values[realN] = value * j;
            ++realN;
        }
        if (count > 0) {
            weights[realN] = weight * count;
            values[realN] = value * count;
            ++realN;
        }
    }

    for (int i = 0; i < realN; ++i) {
        for (int j = W; j >= weights[i]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}