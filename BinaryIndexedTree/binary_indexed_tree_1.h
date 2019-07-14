// 树状数组（支持区间查询和单点更新）
// 洛谷P3374

#include <iostream>
using namespace std;

#define LOWBIT(x) ((x)&(-(x)))
int tree[500000] = {0};  // 树状数组须初始化为0

// 单点更新（a[pos] += val）
void update(int tree[], int length, int pos, int val) {
    int i = pos;
    while (i <= length) {
        tree[i] += val;
        i += LOWBIT(i);
    }
}

// 区间求和（a[1]+a[2]+...+a[pos]）
int sum(const int tree[], int pos) {
    int i = pos;
    int result = 0;
    while (i > 0) {
        result += tree[i];
        i -= LOWBIT(i);
    }
    return result;
}

// 初始化，由a数组构造tree数组
void init(int a[], int tree[], int length) {
    for (int i = 1; i <= length; ++i) {
        update(tree, length, i, a[i]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int num;
        cin >> num;
        update(tree, N, i, num);
    }

    for (int i = 0; i < M; ++i) {
        int command, op1, op2;
        cin >> command >> op1 >> op2;
        if (command == 1) {
            update(tree, N, op1, op2);
        } else {
            cout << sum(tree, op2) - sum(tree, op1 - 1) << endl;
        }
    }

    return 0;
}
