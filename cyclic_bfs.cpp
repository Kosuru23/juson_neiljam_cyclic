#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool bfs(int start, vector<vector<int>>& adj, vector<bool>& visited, int n) {
    queue<pair<int, int>> q;
    q.push({start, -1});
    visited[start] = true;

    cout << "BFS Traversal: ";

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        cout << node << " ";

        for (int neighbor = 0; neighbor < n; ++neighbor) {
            if (adj[node][neighbor]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    int size, start;
    
    cout<<"This is for Breadth First Search Traversal \n";
    cout<<"Input for the size of the adjacent matrix: ";
    cin>>size;

    vector<vector<int>> adj(size, vector<int>(size));
    cout << "Enter the adjacency matrix (" << size << " x " << size << "):\n";

    for(int i = 0; i < size; i++) {
        cout<<" Row " << i << ": ";
        for (int j = 0; j < size; j++)
        {
            cin >> adj[i][j];
        }
    }

    vector<bool> visited(size, false);
    bool isCyclic = false;

    for(int i = 0; i < size; i++) {
        if (!visited[i]) {
            if (bfs(i, adj, visited, size)) {
                isCyclic = true;
            }
        }
    }

    cout << "\nThe graph is "; 
    if(isCyclic == true) {
        cout<<"cyclic.";
    }
    else {
        cout<<"acyclic.";
    }
    return 0;
}
