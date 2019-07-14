// 线段树（支持区间查询和区间更新）
// 洛谷P3372

#include <iostream>
using namespace std;

typedef long long Long;
const int MAX_SIZE = 1000000;
Long tree[MAX_SIZE << 2];  // 线段树要开4倍的空间
Long tag[MAX_SIZE << 2] = {0};  // 引入lazy标记，记录当前结点更新的值
Long arr[MAX_SIZE];
int N, M;

// 左孩子和右孩子
#define LEFT_CHILD(node) ((node) * 2 + 1)
#define RIGHT_CHILD(node) ((node) * 2 + 2)

// 根据arr数组构建线段树
void build_tree(int left, int right, int node) {
    if (left == right) {
        tree[node] = arr[left];
    } else {
        int mid = (left + right) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        build_tree(left, mid, left_child);
        build_tree(mid + 1, right, right_child);
        tree[node] = tree[left_child] + tree[right_child];
    }
}

// 将node结点的lazy tag值向子结点传递
void push_down(int node, int left, int right) {
    int mid = (left + right) >> 1;
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    tree[left_child] += (mid - left + 1) * tag[node];
    tag[left_child] += tag[node];  // 将tag值向下传递
    tree[right_child] += (right - mid) * tag[node];
    tag[right_child] += tag[node];
    tag[node] = 0;
}

// 区间更新，将arr[left~right]范围内的元素加上val
void update(int left, int right, Long val, int nodeLeft, int nodeRight, int node) {
    if (nodeRight < left || right < nodeLeft)
        return;
    if (left <= nodeLeft && nodeRight <= right) {
        tree[node] += val * (nodeRight - nodeLeft + 1);
        tag[node] += val;
    } else {
        push_down(node, nodeLeft, nodeRight);
        int mid = (nodeLeft + nodeRight) >> 1;
        int left_child = LEFT_CHILD(node);
        int right_child = RIGHT_CHILD(node);
        update(left, right, val, nodeLeft, mid, left_child);
        update(left, right, val, mid + 1, nodeRight, right_child);
        tree[node] = tree[left_child] + tree[right_child];
    }
}

// 区间查询，即求sum(arr[left~right])
Long query(int left, int right, int nodeLeft, int nodeRight, int node) {
    if (left <= nodeLeft && nodeRight <= right)
        return tree[node];
    if (nodeRight < left || right < nodeLeft)
        return 0;
    push_down(node, nodeLeft, nodeRight);
    int mid = (nodeLeft + nodeRight) >> 1;
    int left_child = LEFT_CHILD(node);
    int right_child = RIGHT_CHILD(node);
    return query(left, right, nodeLeft, mid, left_child)
           + query(left, right, mid + 1, nodeRight, right_child);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    build_tree(0, N - 1, 0);
    for (int i = 0; i < M; ++i) {
        int op, left, right;
        Long val;
        cin >> op >> left >> right;
        --left, --right;
        if (op == 1) {
            cin >> val;
            update(left, right, val, 0, N - 1, 0);
        } else {
            cout << query(left, right, 0, N - 1, 0) << endl;
        }
    }

    return 0;
}