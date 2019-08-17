// 拓扑排序
// 紫书P167
// UVA-10305

#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int head[105];
struct Edge {
    int dest;
    int next;
} edges[10005];
int edges_cnt;

void addEdge(int src, int dest) {
    ++edges_cnt;
    edges[edges_cnt].dest = dest;
    edges[edges_cnt].next = head[src];
    head[src] = edges_cnt;
}

int ans[105];
int ans_cur;
int visited[105];  // 0:未访问过 1:已被dfs完整访问完 -1:dfs正在访问

bool dfs(int v) {
    visited[v] = -1;
    int edge = head[v];
    while (edge > 0) {
        int dest = edges[edge].dest;
        if (visited[dest] == -1 || (visited[dest] == 0 && !dfs(dest))) {
            return false;
        }
        edge = edges[edge].next;
    }
    ans[ans_cur] = v;
    --ans_cur;
    visited[v] = 1;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    while ((cin >> N >> M) && !(N == 0 && M == 0)) {
        memset(head, 0, sizeof(int) * (N + 1));
        memset(visited, 0, sizeof(int) * (N + 1));
        edges_cnt = 0;
        for (int i = 0; i < M; ++i) {
            int src, dest;
            cin >> src >> dest;
            addEdge(src, dest);
        }

        ans_cur = N - 1;
        bool cycle = false;
        for (int i = 1; i <= N; ++i) {
            if (visited[i] == 0 && !dfs(i)) {
                cycle = true;
                break;
            }
        }
        if (!cycle) {
            cout << ans[0];
            for (int i = 1; i < N; ++i) {
                cout << ' ' << ans[i];
            }
            cout << endl;
        } else {
            cout << "cycle!" << endl;
        }
    }

    return 0;
}
