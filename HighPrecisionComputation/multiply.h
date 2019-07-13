#include <iostream>
#include <string>
using namespace std;

const int CAPACITY = 500;
int a[CAPACITY], b[CAPACITY], c[CAPACITY];

// 高精度乘法（opnd1*opnd2→result）
void multiply(const int opnd1[], const int opnd2[], int result[], int length) {
    fill(result, result + length, 0);
    for (int i = 0; i < length; ++i) {
        if (b[i] > 0) {
            int carry = 0;
            for (int j = 0; j < length; ++j) {
                result[i + j] += b[i] * a[j] + carry;
                carry = result[i + j] / 10;
                result[i + j] %= 10;
            }
        }
    }
}

// 输出数组中的结果
void output(const int result[], int length) {
    int begin_pos = length - 1;
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
    multiply(a, b, c, CAPACITY);
    output(c, CAPACITY);

    return 0;
}