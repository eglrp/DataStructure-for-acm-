// 01背包问题（二维数组）
// 有一个背包，最多能装质量为N的物品
// 现在有M个物品，已知每个物品的质量和价值
// 求出背包所能装下的最大价值
// dp[i][j]表示用容量为j的背包装前i件物品能获得的最大价值
// dp[i][j] = max{dp[i-1][j], dp[i-1][j-weight[i]]+value[i]}
// 洛谷P1060

#include <iostream>
#include <cstring>
using namespace std;

int value[25], weight[25];
int dp[25][30001];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> weight[i] >> value[i];
        value[i] *= weight[i];
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (j >= weight[i]) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[M][N];

    return 0;
}
