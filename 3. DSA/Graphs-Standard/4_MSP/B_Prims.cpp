#include<bits/stdc++.h>
using namespace std;
// https://www.youtube.com/watch?v=mJcZjjKzeqk
using lli = long long int;
using ii = pair<lli,lli>;
using state = pair<int,ii>;
#define S second
#define F first

lli n,m;
vector<vector<ii>> g;
vector<lli> vis;
//Space complexity O(V+E)
//Time complexity O(ElogE)

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    int u,v,w;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    vector<ii> mst;
    lli mst_cost = 0;
    priority_queue<state,vector<state>,greater<state>> pq; //stores {wt, {node, parent}} 
    pq.push({0,{0,-1}}); //assuming 0's parent as -1

    while(!pq.empty())
    {
        state cur = pq.top(); pq.pop();
        if(vis[cur.S.F]) continue;

        vis[cur.S.F] = 1;
        if(cur.S.S!=-1)
        {
            mst.push_back(cur.S);
            mst_cost += cur.F;
        }
        for(auto v: g[cur.S.F])
        {
            int nei = v.S, wt = v.F;
            if(!vis[nei])
            {
                pq.push( {wt,{nei,cur.S.F}} );
            }
        }
    }
    cout<<mst_cost<<'\n';
    //edges in mst
    for(auto i: mst){
        cout<<i.F<<' '<<i.S<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}
/*
Required data structures
1. Min heap
2. Visited array
3. Mst list that will store all the edges that are a part of MST

Datatypes of our data structures
Visited array => int
Mst list =>  (weight , node name , node parent)



Steps
1. Mark the visited array as 0 for all the nodes

2. Start with 0th node and push
(0,0,-1)
explanation:  -1 means 0 is the genesis node
Mark 0 as visited

3. Push all the neighbours of 0 in pq Do not mark them visited  (footnote 1)
Since its a min heap the edge with minimum weight will be at the top

4. Pick up the top edge , insert it in the mst , mark the picked node as visited , insert all neighbours of picked node into pq

5. keep repeating steps 3 and 4 untill all the nodes have been picked up and thats when the algorithm ends


footnote:
1. why to not mark it visited?
in bfs , when we push the element inside a queue we mark it as visited cause that element will be picked up later for sure (algorithm ends only when the queue is empty )
but in msts case even if we push the edge into pq , theres no surety that the edge will be picked up . when prims algo ends there are still a few non accepted edges present in the pq hence we only mark it visited once its picked up from pq
*/