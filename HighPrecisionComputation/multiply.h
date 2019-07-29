#include <iostream>
#include <string>
using namespace std;

const int SIZE = 2005;
const int RESULT_SIZE = SIZE * 2 + 1;
int a[SIZE], b[SIZE], c[RESULT_SIZE];

// 高精度乘法（opnd1*opnd2→result）
void multiply(const int opnd1[], const int opnd2[], int result[]) {
    for (int i = 0; i < SIZE; ++i) {
        if (b[i] > 0) {
            int carry = 0;
            for (int j = 0; j < SIZE; ++j) {
                result[i + j] += b[i] * a[j] + carry;
                carry = result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    }
}

// 输出数组中的结果
void output(const int result[]) {
    int begin_pos = RESULT_SIZE - 1;
    while (begin_pos >= 0 && result[begin_pos] == 0)
        --begin_pos;
    if (begin_pos < 0) {
        cout << "0" << endl;
    } else {
        for (int i = begin_pos; i >= 0; --i) {
            cout << result[i];
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    string num1, num2;
    cin >> num1 >> num2;

    int length1 = num1.length();
    int length2 = num2.length();
    for (int i = 0; i < length1; ++i) {
        a[i] = num1[length1 - 1 - i] - '0';
    }
    for (int i = 0; i < length2; ++i) {
        b[i] = num2[length2 - 1 - i] - '0';
    }
    multiply(a, b, c);
    output(c);

    return 0;
}