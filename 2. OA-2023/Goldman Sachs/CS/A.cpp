#include <iostream>
#include<bits/stdc++.h>
#include <vector>

using namespace std;

void dfs(int node, const vector<vector<int>>& graph, vector<bool>& visited, vector<bool>& in_stack, set<int>& cycle_nodes) {
    if (visited[node]) {
        return;
    }

    visited[node] = true;
    in_stack[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited, in_stack, cycle_nodes);
        } else if (in_stack[neighbor]) {
            // If the neighbor is already in the current DFS stack, it means a cycle is present.
            // Mark the nodes in the cycle as part of a cycle and backtrack.
            cycle_nodes.insert(neighbor);
        }
    }

    in_stack[node] = false;
}

set<int> find_non_cyclic_nodes(int N, const vector<vector<int>>& graph) {
    vector<bool> visited(N + 1, false);
    vector<bool> in_stack(N + 1, false);
    set<int> cycle_nodes;

    for (int node = 1; node <= N; ++node) {
        if (!visited[node]) {
            dfs(node, graph, visited, in_stack, cycle_nodes);
        }
    }

    // Finally, the non-cyclic nodes are those not present in the cycle_nodes set.
    set<int> non_cyclic_nodes;
    for (int node = 1; node <= N; ++node) {
        if (!cycle_nodes.count(node)) {
            non_cyclic_nodes.insert(node);
        }
    }

    return non_cyclic_nodes;
}

int main() {
    int N, M; // N: number of nodes, M: number of edges
    cin >> N >> M;

    vector<vector<int>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int u, v,p1,p2;
        cin >> u >> v>>p1>>p2;
        if(p1>p2) graph[u].push_back(v); // Edge from u to v
        else graph[v].push_back(u);
    }

    set<int> non_cyclic_nodes = find_non_cyclic_nodes(N, graph);

    cout << "Nodes not part of any cycle: ";
    for (int node : non_cyclic_nodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
