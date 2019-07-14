// 树状数组（支持区间查询和区间更新）
// 洛谷P3372
// a为数据数组，令数组b为b[i]=a[i]-a[i-1]，用tree1维护b
// 令数组c为c[i]=b[i]*(i-1)，用tree2维护b
// 区间查询：sum(a[1~i]) = (b[1]) + (b[1]+b[2]) + ... + (b[1]+...+b[i])
// = b[1]*i + b[2]*(i-1) + ... + b[i]
// = i * (b[1]+b[2]+...+b[i]) - (b[1]*0 + b[2]*1 + ... + b[i]*(i-1))
// = i * query1(i) - query2(i)

#include <iostream>
using namespace std;

typedef long long Long;
int N, M;
Long tree1[500001];
Long tree2[500001];
#define LOWBIT(x) (x&(-(x)))

void update(Long tree[], int pos, Long val) {
    int i = pos;
    while (i <= N) {
        tree[i] += val;
        i += LOWBIT(i);
    }
}

Long query(const Long tree[], int pos) {
    int i = pos;
    Long result = 0;
    while (i > 0) {
        result += tree[i];
        i -= LOWBIT(i);
    }
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    Long num, last_num = 0;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        Long bi = num - last_num;
        update(tree1, i + 1, bi);
        update(tree2, i + 1, bi * i);
        last_num = num;
    }
    for (int i = 0; i < M; ++i) {
        int op, x, y;
        Long val;
        cin >> op >> x >> y;
        if (op == 1) {
            cin >> val;
            update(tree1, x, val);
            update(tree1, y + 1, -val);
            update(tree2, x, val * (x - 1));
            update(tree2, y + 1, -val * y);
        } else {
            Long sumX = (x-1) * query(tree1, x-1) - query(tree2, x-1);
            Long sumY = y * query(tree1, y) - query(tree2, y);
            cout << sumY - sumX << endl;
        }
    }

    return 0;
}