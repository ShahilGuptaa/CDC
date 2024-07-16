#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    bool printNodesNotInCycleUtil(
        int v, bool visited[], bool *rs,
        bool *cyclePart);

    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printNodesNotInCycle();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
bool Graph::printNodesNotInCycleUtil(
    int v, bool visited[],
    bool *recStack, bool *cyclePart)
{
    if (visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;
        for (auto &child : adj[v])
        {
            if (!visited[child] && printNodesNotInCycleUtil(child, visited,recStack, cyclePart))
            {
                cyclePart[child] = 1;
                return true;
            }
            else if (recStack[child])
            {
                cyclePart[child] = 1;
                return true;
            }
        }
    }

    recStack[v] = false;
    return false;
}
void Graph::printNodesNotInCycle()
{
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    bool *cyclePart = new bool[V];

    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
        cyclePart[i] = false;
    }
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (printNodesNotInCycleUtil(
                    i, visited, recStack,
                    cyclePart))
            {
                cyclePart[i] = 1;
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        if (cyclePart[i] == 0)
        {
            cout << i << " ";
        }
    }
}
void solve(int N, int E, int Edges[][4])
{
    Graph g(N+1);
    for (int i = 0; i < E; i++)
    {
        if(Edges[i][2]>Edges[i][3]) g.addEdge(Edges[i][0],Edges[i][1]);
        else g.addEdge(Edges[i][1],Edges[i][0]);
    }
    g.printNodesNotInCycle();
}
int main()
{
    int N;
    int E;
    cin>>N>>E;

    int Edges[E][4] ;
    for(int i=0;i<E;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        Edges[i][0] = a;
        Edges[i][1] = b;
        Edges[i][2] = c;
        Edges[i][3] = d;
    }
    solve(N, E, Edges);
    return 0;
}