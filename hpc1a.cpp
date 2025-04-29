#include <iostream>
#include <queue>
#include <vector>
#include <omp.h>
using namespace std;

vector<int> graph[100];
bool visited[100];

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " ";

        #pragma omp parallel for
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];

            if (!visited[v]) {
                #pragma omp critical
                {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
        }
    }
}

int main() {
    int n, m, start;
    cin >> n >> m >> start;

    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    bfs(start);
    return 0;
}
