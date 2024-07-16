#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
class Solution {
public:
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& r) 
    {
        vector<vector<ii>> g(n); vector<lli> dist(n,1e18); dist[0] = 0;
        vector<lli> ways(n,0); ways[0] = 1;
        vector<lli> vis(n,0);
        priority_queue<ii,vector<ii>,greater<ii>> pq;
        pq.push({dist[0],0}); 

        for(lli i=0;i<r.size();i++)
        {
            lli u = r[i][0], v = r[i][1], wt = r[i][2];
            g[u].push_back({v,wt});
            g[v].push_back({u,wt});
        }

        while(!pq.empty())
        {
            ii cur = pq.top(); pq.pop();
            lli cn = cur.second, cdist = cur.first;

            //to prevent multiple counting
            if(vis[cn]) continue;
            vis[cn] = 1;
            
            for(auto v: g[cn])
            {
                lli nn = v.first, wt = v.second;
                if(dist[nn] > cdist + wt)
                {
                    dist[nn] = cdist + wt;
                    ways[nn] = (ways[cn]%mod);
                    pq.push({dist[nn],nn});
                }
                else if(dist[nn] == dist[cn]+wt)
                {
                    ways[nn] = ( (ways[nn]%mod) + (ways[cn]%mod) )%mod;
                }
            }
        }
        return ways[n-1];
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m; cin>>n>>m;
    vector<vector<int>> t;
    for(int i=0;i<m;i++)
    {
        vector<int> edge(3);
        for(int j=0;j<3;j++) cin>>edge[j];
        t.push_back(edge);
    }
    Solution obj;
    cout<<obj.countPaths(n,t)<<'\n';
}