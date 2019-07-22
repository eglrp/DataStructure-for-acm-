// 01背包问题（二维数组优化成一维数组）
// 有一个背包，最多能装质量为N的物品
// 现在有M个物品，已知每个物品的质量和价值
// 求出背包所能装下的最大价值
// dp[n]表示容量为n的包所能装的最大价值
// 洛谷P1060

#include <iostream>
#include <cstring>
using namespace std;

int value[25], weight[25];
int dp[30001];
int N, M;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 1; i <= M; ++i) {
        cin >> weight[i] >> value[i];
        value[i] *= weight[i];
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = N; j > 0; --j) {
            if (j >= weight[i]) {
                dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
            }
        }
    }

    cout << dp[N];

    return 0;
}
