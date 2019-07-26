// 高精度减法
// 洛谷P2142

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10001;
int a[SIZE], b[SIZE], c[SIZE];

// 从输入流读入操作数
void readInt(int opnd[]) {
    string digits;
    cin >> digits;
    int length = digits.length();
    for (int i = 0; i < length; ++i) {
        int digit = digits[i] - '0';
        opnd[length - 1 - i] = digit;
    }
}

// 高精度减法（opnd1-opnd2→result）
// 如果结果为负，置negative为true
void subtract(int opnd1[], int opnd2[], int result[], bool& negative) {
    negative = false;
    for (int i = SIZE - 1; i >= 0; --i) {
        if (opnd1[i] < opnd2[i]) {
            negative = true;
            swap(opnd1, opnd2);
            break;
        } else if (opnd1[i] > opnd2[i])
            break;
    }

    for (int i = 0; i < SIZE; ++i) {
        result[i] += opnd1[i] - opnd2[i];
        if (result[i] < 0) {
            result[i] += 10;
            --result[i + 1];
        }
    }
}

// 输出数组中的结果
void output(const int result[], bool negative) {
    if (negative)
        cout << '-';
    int begin_pos = SIZE - 1;
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

    readInt(a);
    readInt(b);

    bool negative;
    subtract(a, b, c, negative);

    output(c, negative);

    return 0;
}