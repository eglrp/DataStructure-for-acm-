// 完全背包问题
// 有N种物品和一个载重量为W的背包，每种物品都有无限件可用。
// 第i种物品的重量是weights[i]，价值是values[i]。
// 求解将哪些物品装入背包，可使这些物品的总重量不超过背包载重量，且总价值最大。
// AcWing P3

#include <iostream>
using namespace std;

int N, W;
int weights[1000], values[1000];
int dp[1001];

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> W;
    for (int i = 0; i < N; ++i) {
        cin >> weights[i] >> values[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = weights[i]; j <= W; ++j) {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}