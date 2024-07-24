#include <iostream>
#include <vector>

using namespace std;

// Función de búsqueda en profundidad para contar los caminos
void dfs(const vector<vector<int>>& graph, int src, int dest, vector<bool>& visited, int& pathCount) {
    visited[src] = true;

    if (src == dest) {
        pathCount++;
    } else {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[src][i] && !visited[i]) {
                dfs(graph, i, dest, visited, pathCount);
            }
        }
    }

    visited[src] = false;
}

int main() {
    cout << "Input: " << endl;
    int testCases;
    cin >> testCases;

    vector<int> results;

    for (int t = 0; t < testCases; t++) {
        int n;
        cin >> n;

        vector<vector<int>> graph(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> graph[i][j];
            }
        }

        int src, dest;
        cin >> src >> dest;

        vector<bool> visited(n, false);
        int pathCount = 0;
        dfs(graph, src, dest, visited, pathCount);

        results.push_back(pathCount);
    }
    cout << "" << endl;
    cout << "Output: " << endl;
    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}