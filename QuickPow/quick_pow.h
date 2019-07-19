// 快速幂
// 可快速求出n^m

#include <iostream>
using namespace std;

const int MOD = 10000000;

int main() {
    int N, M;
    cin >> N >> M;

    long long result = 1;
    long long a = N;
    int b = M;
    while (b > 0) {
        if (b & 1) {
            result = result * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }

    cout << result % MOD << endl;

    return 0;
}