// Dijkstra算法
// 适用于非负权图
// 洛谷P4479

#include <iostream>
#include <queue>
using namespace std;

const int INF = 0x3fffffff;

int N, M, S;
struct Edge {
    int dest, next, weight;
} edges[400001];
int edge_cnt = 1;
int head[100001];
int dis[100001];
bool visited[100001];

struct Node {
    int dis, vertex;

    Node(int dis, int vertex) : dis(dis), vertex(vertex) {}

    bool operator<(const Node& other) const {
        return dis > other.dis;
    }
};
priority_queue<Node> q;

void addEdge(int src, int dest, int weight) {
    edges[edge_cnt].weight = weight;
    edges[edge_cnt].dest = dest;
    edges[edge_cnt].next = head[src];
    head[src] = edge_cnt;
    ++edge_cnt;
}

void dijkstra() {
    for (int i = 1; i <= N; ++i) {
        dis[i] = INF;
    }
    dis[S] = 0;
    q.emplace(Node(0, S));
    while (!q.empty()) {
        Node node = q.top();
        q.pop();
        int vertex = node.vertex;
        if (!visited[vertex]) {
            visited[vertex] = true;
            for (int i = head[vertex]; i > 0; i = edges[i].next) {
                int dest = edges[i].dest;
                if (dis[vertex] + edges[i].weight < dis[dest]) {
                    dis[dest] = dis[vertex] + edges[i].weight;
                    if (!visited[dest]) {
                        q.emplace(Node(dis[dest], dest));
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M >> S;
    for (int i = 0; i < M; ++i) {
        int U, V, W;
        cin >> U >> V >> W;
        addEdge(U, V, W);
    }
    dijkstra();
    for (int i = 1; i <= N; ++i) {
        cout << dis[i] << ' ';
    }
    cout << endl;

    return 0;
}