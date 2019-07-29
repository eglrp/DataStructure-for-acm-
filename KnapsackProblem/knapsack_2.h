// 01背包问题（二维数组优化成一维数组）
// 有一个背包，最多能装质量为W的物品
// 现在有N个物品，已知每个物品的质量和价值
// 求出背包所能装下的最大价值
// dp[n]表示容量为n的包所能装的最大价值
// AcWing P2

#include <iostream>
using namespace std;

int weights[1001];
int values[1001];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    int N, W;
    cin >> N >> W;
    for (int i = 1; i <= N; ++i) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = W; j >= weights[i]; --j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}