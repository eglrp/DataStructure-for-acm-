// 矩阵快速幂
// 对于方阵a，可快速求出a^k
// 洛谷P3390

#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX_SIZE = 100;  // 矩阵的最大阶
const int MOD = 1000000007;  // 对每一次中间结果取模

struct Matrix {
    ll matrix[MAX_SIZE][MAX_SIZE];
    int size;

    Matrix(int size) : size(size) {}

    // 从cin读入矩阵
    void readData() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cin >> matrix[i][j];
            }
        }
    }

    // 构建单位矩阵
    void buildUnitMatrix() {
        memset(matrix, 0, sizeof(matrix));
        for (int i = 0; i < size; ++i) {
            matrix[i][i] = 1;
        }
    }

    // 矩阵乘法
    Matrix operator*(const Matrix& other) {
        Matrix result(size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                ll& val = result.matrix[i][j];
                val = 0;
                for (int k = 0; k < size; ++k) {
                    val = (val + matrix[i][k] * other.matrix[k][j] % MOD) % MOD;
                }
            }
        }
        return result;
    }

    // 输出矩阵
    void print() {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    int N;
    ll K;
    cin >> N >> K;
    Matrix a(N), ans(N);
    ans.buildUnitMatrix();
    a.readData();

    // 矩阵快速幂
    ll power = K;
    while (power > 0) {
        if (power & 1) {
            ans = ans * a;
        }
        a = a * a;
        power >>= 1;
    }

    ans.print();

    return 0;
}