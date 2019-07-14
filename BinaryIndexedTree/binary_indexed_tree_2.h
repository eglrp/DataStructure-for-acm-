// 树状数组（支持单点查询和区间更新）
// 洛谷P3368
// 本质是：对于数组a，用树状数组维护数组b，其中b[i]=a[i]-a[i-1]
// 查询：a[i]=b[1]+b[2]+...+b[i]
// 区间更新：假设更新a[x~y]，则b[x]+=val，b[y+1]-=val

#include <iostream>
using namespace std;

typedef long long Long;
int N, M;
Long tree[500001];
#define LOWBIT(x) (x&(-(x)))

void update(int pos, Long val) {
    int i = pos;
    while (i <= N) {
        tree[i] += val;
        i += LOWBIT(i);
    }
}

Long query(int pos) {
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
        update(i + 1, num - last_num);
        last_num = num;
    }
    for (int i = 0; i < M; ++i) {
        int op, x, y;
        Long val;
        cin >> op >> x;
        if (op == 1) {
            cin >> y >> val;
            update(x, val);
            if (y + 1 <= N)
                update(y + 1, -val);
        } else {
            cout << query(x) << endl;
        }
    }

    return 0;
}