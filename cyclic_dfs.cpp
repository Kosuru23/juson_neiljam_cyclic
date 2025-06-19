#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool iterativeDFS(int start, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& traversal) {
    stack<pair<int, int>> st;  
    st.push({start, -1});
    bool hasCycle = false;

    while (!st.empty()) {
        int node = st.top().first;
        int parent = st.top().second;
        st.pop();

        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        traversal.push_back(node);

        for (int neighbor = adj.size() - 1; neighbor >= 0; --neighbor) {
            if (adj[node][neighbor]) {
                if (!visited[neighbor]) {
                    st.push({neighbor, node});
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
    int size;
    
    cout << "This is for Depth First Search Traversal \n";
    cout << "Input for the size of the adjacency matrix: ";
    cin >> size;

    vector<vector<int>> adj(size, vector<int>(size));
    cout << "Enter the adjacency matrix (" << size << " x " << size << "):\n";

    for(int i = 0; i < size; i++) {
        cout << " Row " << i << ": ";
        for (int j = 0; j < size; j++) {
            cin >> adj[i][j];
        }
    }

    int startNode;
    cout << "Enter the starting node (0 to " << size - 1 << "): ";
    cin >> startNode;

    vector<bool> visited(size, false);
    vector<int> traversal;
    bool isCyclic = iterativeDFS(startNode, adj, visited, traversal);

    cout << "DFS Traversal starting from node " << startNode << ": ";
    for (int v : traversal)
        cout << v << " ";

    cout << "\nThe graph is "; 
    if(isCyclic) {
        cout << "cyclic.";
    }
    else {
        cout << "acyclic.";
    }

    return 0;
}