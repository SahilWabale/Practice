#include <iostream>
#include <vector>
#include <stack>
#include <omp.h>
using namespace std;

vector<int> graph[100];
bool visitedDFS[100];

void parallelDFS(int start){
    visitedDFS[start] = true;
    cout<<start<<" ";
    #pragma omp parallel for
    for(int i=0;i<graph[start].size();i++){
        if(!visitedDFS[graph[start][i]])
            parallelDFS(graph[start][i]);
    }
}

int main() {
    int n, m, start;
    cout << "Enter number of nodes, edges and starting node: ";
    cin >> n >> m >> start;
    cout << "Enter " << m << " edges (u v):\n";
    for (int i = 0, u, v; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << "DFS Traversal:\n";
 parallelDFS(start);
}