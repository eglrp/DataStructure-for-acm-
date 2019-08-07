// Prim算法
// Prim在稠密图中比Kruskal优，在稀疏图中比Kruskal劣
// 洛谷P3366

#include <iostream>
#include <climits>
using namespace std;

int N, M;

// 链式前向星
struct Edge {
    int dest;  // 这条边的终点
    int weight;  // 权值
    int next;  // 与这条边同起点的下一条边的存储位置，为0相当于链表node.next==NULL
} edges[400001];
// 存储以i为起点第一条边的存储位置，注意无向图要开两倍数组
int head[5001];
// 存储已经加入最小生成树的点到未加入点的最短距离，比如1号2号已加入树，则dis[3]=min(1->3, 2->3)
int dis[5001];
// 已经加入最小生成树的顶点
bool used[5001];
int edge_cnt = 1;  // 从1开始，0是特殊标记，相当于链表node.next==NULL

// 链式前向星加边
void addEdge(int src, int dest, int weight) {
    edges[edge_cnt].weight = weight;
    edges[edge_cnt].dest = dest;
    edges[edge_cnt].next = head[src];
    head[src] = edge_cnt;
    ++edge_cnt;
}

// Prim算法，求出最小生成树的各边长度之和
int prim() {
    int total_length = 0;
    for (int i = 2; i <= N; ++i) {
        dis[i] = INT_MAX;
    }
    for (int i = head[1]; i > 0; i = edges[i].next) {
        // 此处使用min是考虑到重边的情况
        dis[edges[i].dest] = min(dis[edges[i].dest], edges[i].weight);
    }
    int node = 1;
    for (int i = 0; i < N - 1; ++i) {  // 最小生成树的边数等于点数-1
        used[node] = true;
        int min_weight = INT_MAX;
        // 枚举每一个未使用的点，找出最小的权值作为新的边
        for (int j = 1; j <= N; ++j) {
            if (!used[j] && dis[j] < min_weight) {
                min_weight = dis[j];
                node = j;
            }
        }
        total_length += min_weight;
        // 枚举node的所有连边，更新dis数组
        for (int j = head[node]; j > 0; j = edges[j].next) {
            int dest = edges[j].dest;
            if (!used[dest] && edges[j].weight < dis[dest])
                dis[dest] = edges[j].weight;
        }
    }
    return total_length;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        addEdge(X, Y, Z);
        addEdge(Y, X, Z);
    }

    cout << prim() << endl;

    return 0;
}