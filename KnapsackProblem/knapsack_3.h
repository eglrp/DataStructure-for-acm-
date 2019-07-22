// 完全背包问题
// 有一个背包容量为capacity，有count件物品，每件有任意数量，求包能装的最大价值
// 洛谷P1616

#include <iostream>
using namespace std;

int capacity, count;
int weight[10001];
int value[10001];
int dp[100001];

int main() {
    ios::sync_with_stdio(false);
    cin >> capacity >> count;
    for (int i = 1; i <= count; ++i) {
        cin >> weight[i] >> value[i];
    }

    for (int i = 1; i <= count; ++i) {
        for (int j = weight[i]; j <= capacity; ++j) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[capacity] << endl;

    return 0;
}