// C++ program for the above approach
 
#include <bits/stdc++.h>
using namespace std;
 
class Graph {
 
    // No. of vertices
    int V;
 
    // Stores the Adjacency List
    list<int>* adj;
    bool printNodesNotInCycleUtil(
        int v, bool visited[], bool* rs,
        bool* cyclePart);
 
public:
    // Constructor
    Graph(int V);
 
    // Member Functions
    void addEdge(int v, int w);
    void printNodesNotInCycle();
};
 
// Function to initialize the graph
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
// Function that adds directed edges
// between node v with node w
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
 
// Function to perform DFS Traversal
// and return true if current node v
// forms cycle
bool Graph::printNodesNotInCycleUtil(
    int v, bool visited[],
    bool* recStack, bool* cyclePart)
{
 
    // If node v is unvisited
    if (visited[v] == false) {
 
        // Mark the current node as
        // visited and part of
        // recursion stack
        visited[v] = true;
        recStack[v] = true;
 
        // Traverse the Adjacency
        // List of current node v
        for (auto& child : adj[v]) {
 
            // If child node is unvisited
            if (!visited[child]
                && printNodesNotInCycleUtil(
                       child, visited,
                       recStack, cyclePart)) {
 
                // If child node is a part
                // of cycle node
                cyclePart[child] = 1;
                return true;
            }
 
            // If child node is visited
            else if (recStack[child]) {
                cyclePart[child] = 1;
                return true;
            }
        }
    }
 
    // Remove vertex from recursion stack
    recStack[v] = false;
    return false;
}
 
// Function that print the nodes for
// the given directed graph that are
// not present in any cycle
void Graph::printNodesNotInCycle()
{
 
    // Stores the visited node
    bool* visited = new bool[V];
 
    // Stores nodes in recursion stack
    bool* recStack = new bool[V];
 
    // Stores the nodes that are
    // part of any cycle
    bool* cyclePart = new bool[V];
 
    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
        cyclePart[i] = false;
    }
 
    // Traverse each node
    for (int i = 0; i < V; i++) {
 
        // If current node is unvisited
        if (!visited[i]) {
 
            // Perform DFS Traversal
            if (printNodesNotInCycleUtil(
                    i, visited, recStack,
                    cyclePart)) {
 
                // Mark as cycle node
                // if it return true
                cyclePart[i] = 1;
            }
        }
    }
 
    // Traverse the cyclePart[]
    for (int i = 0; i < V; i++) {
 
        // If node i is not a part
        // of any cycle
        if (cyclePart[i] == 0) {
            cout << i << " ";
        }
    }
}
 
// Function that print the nodes for
// the given directed graph that are
// not present in any cycle
void solve(int N, int E,
           int Edges[][2])
{
 
    // Initialize the graph g
    Graph g(N);
 
    // Create a directed Graph
    for (int i = 0; i < E; i++) {
        g.addEdge(Edges[i][0],
                  Edges[i][1]);
    }
 
    // Function Call
    g.printNodesNotInCycle();
}
 
// Driver Code
int main()
{
    // Given Number of nodes
    int N = 6;
 
    // Given Edges
    int E = 7;
 
    int Edges[][2] = { { 0, 1 }, { 1, 2 },
                       { 1, 3 }, { 3, 4 },
                       { 4, 1 }, { 4, 5 },
                                 { 4, 8 } ,{ 5, 6 }, { 6, 7 },{ 7, 4 }  };
 
    // Function Call
    solve(N, E, Edges);
 
    return 0;
}