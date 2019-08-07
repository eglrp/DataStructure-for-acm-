// 并查集
// 洛谷P3367

#include <iostream>
using namespace std;

int M, N;
int ancestor[10001];  // 存储每个结点的祖先结点

// 寻找某个结点的祖先结点
int findAncestor(int node) {
    if (node == ancestor[node])
        return node;
    else
        return ancestor[node] = findAncestor(ancestor[node]);  // 路径压缩
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;

    // 初始化，设置每个结点的父亲结点为自己
    for (int i = 1; i <= N; ++i) {
        ancestor[i] = i;
    }

    while (M--) {
        int Z, X, Y;
        cin >> Z >> X >> Y;

        // 寻找祖先结点
        int ancestorX = findAncestor(X);
        int ancestorY = findAncestor(Y);

        if (Z == 1) {
            ancestor[ancestorX] = ancestorY;
        } else {
            if (ancestorX == ancestorY) {
                cout << 'Y' << endl;
            } else {
                cout << 'N' << endl;
            }
        }
    }

    return 0;
}