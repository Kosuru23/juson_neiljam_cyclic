#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited, int n, vector<int>& traversal) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    bool hasCycle = false;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        traversal.push_back(node);

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (adj[node][neighbor]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent) {
                    hasCycle = true;
                }
            }
        }
    }
    return hasCycle;
}

int main() {
    int size, start;
    
    cout << "This is for Breadth First Search Traversal \n";
    cout << "Input for the size of the adjacency matrix: ";
    cin >> size;

    vector<vector<int>> adj(size, vector<int>(size));
    cout << "Enter the adjacency matrix (" << size << " x " << size << "):\n";

    for (int i = 0; i < size; i++) {
        cout << " Row " << i << ": ";
        for (int j = 0; j < size; j++) {
            cin >> adj[i][j];
        }
    }

    cout << "Enter the starting node (0 to " << size - 1 << "): ";
    cin >> start;

    vector<bool> visited(size, false);
    vector<int> traversal;
    bool isCyclic = bfs(start, adj, visited, size, traversal);

    cout << "BFS Traversal starting from node " << start << ": ";
    for (int v : traversal)
        cout << v << " ";

    cout << "\nThe graph is ";
    if (isCyclic) {
        cout << "cyclic.";
    } else {
        cout << "acyclic.";
    }

    return 0;
}
