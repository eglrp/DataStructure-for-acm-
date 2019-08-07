// Kruskal算法
// Prim在稠密图中比Kruskal优，在稀疏图中比Kruskal劣
// 洛谷P3366

#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

// 毫无亮点的边集数组
struct Edge {
    int src, dest, weight;

    bool operator<(const Edge& other) {
        return weight < other.weight;
    }
} edges[400000];
int ancestor[5001];

int findAncestor(int node) {
    if (node == ancestor[node])
        return node;
    else
        return ancestor[node] = findAncestor(ancestor[node]);
}

int kruskal() {
    sort(edges, edges + M);
    for (int i = 1; i <= N; ++i) {
        ancestor[i] = i;
    }
    int total_length = 0;
    int count = 0;
    for (int i = 0; i < M; ++i) {
        int ancestorSrc = findAncestor(edges[i].src);
        int ancestorDest = findAncestor(edges[i].dest);
        if (ancestorSrc != ancestorDest) {
            ancestor[ancestorSrc] = ancestorDest;
            total_length += edges[i].weight;
            ++count;
            if (count >= N - 1)
                break;
        }
    }
    return total_length;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    cout << kruskal() << endl;

    return 0;
}