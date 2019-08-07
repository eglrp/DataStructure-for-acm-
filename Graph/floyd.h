#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

// 顶点的个数
const int SIZE = 7;

// 表示距离为无穷大
const int INF = 65536;

// 邻接矩阵，同时也是最终两个顶点之间的最短距离
int dis[SIZE][SIZE] = {
        {  0,   5,   7, INF, INF, INF,   2},
        {  5,   0, INF,   9, INF, INF,   3},
        {  7, INF,   0, INF,   8, INF, INF},
        {INF,   9, INF,   0, INF,   4, INF},
        {INF, INF,   8, INF,   0,   5,   4},
        {INF, INF, INF,   4,   5,   0,   6},
        {  2,   3, INF, INF,   4,   6,   0},
};

// 前驱结点
int pre[SIZE][SIZE];

int main() {
    // 初始化pre矩阵
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            pre[i][j] = i;
        }
    }

    // 弗洛伊德算法

    // 遍历中间顶点
    for (int k = 0; k < SIZE; ++k) {
        // 从i顶点出发
        for (int i = 0; i < SIZE; ++i) {
            // 到达j顶点，经过k顶点
            for (int j = 0; j < SIZE; ++j) {
                if (dis[i][k] + dis[k][j] < dis[i][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    pre[i][j] = pre[k][j];
                }
            }
        }
    }

    // 输出最短路径
    printf("   ");
    for (int i = 0; i < SIZE; ++i) {
        printf("  %c", 'A' + i);
    }
    putchar('\n');
    for (int i = 0; i < SIZE; ++i) {
        printf("  %c", 'A' + i);
        for (int j = 0; j < SIZE; ++j) {
            printf("%3d", dis[i][j]);
        }
        putchar('\n');
    }

    // 利用pre矩阵输出最短路线
    // 例如，输出从A到D的最短路线

    int src = 0; // 对应于顶点A
    int dest = 'D' - 'A'; // 对应于顶点D
    stack<int> s;

    int node = dest;
    while (node != src) {
        s.push(node);
        node = pre[src][node];
    }

    putchar('A' + src);
    while (!s.empty()) {
        printf(" -> %c", s.top() + 'A');
        s.pop();
    }

    return 0;
}