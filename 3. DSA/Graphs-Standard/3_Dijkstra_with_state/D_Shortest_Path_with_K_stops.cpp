// https://leetcode.com/problems/cheapest-flights-within-k-stops/submissions/1264469973/?source=submission-noac

#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii= pair<int,int>;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<ii>> g(n);
        int m = flights.size();
        for(int i=0;i<m;i++)
        {
            int u = flights[i][0], v = flights[i][1], wt = flights[i][2];
            g[u].push_back({v,wt});
        }
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue< pair<int,ii> > pq; //#nodes,node,dist
        pq.push({1,{src,0}});

        while(!pq.empty())
        {
            int cnode = pq.front().second.first, cdist = pq.front().second.second, ccnt = pq.front().first;
            pq.pop();
            for(auto v:g[cnode])
            {
                int nn = v.first, wt = v.second;
                //no. of stops to reach nn
                int stops = ccnt+1-2;
                if(stops<=k )
                {
                    if(dist[nn] > cdist+wt)
                    {
                        dist[nn] = cdist + wt;
                        pq.push({ccnt+1,{nn,dist[nn]}});
                    }
                }
            }
        }
        if(dist[dst]!=1e9) return dist[dst];
        else return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n,m,k; cin>>n>>m>>k;
    vector<vector<int>> t;
    for(int i=0;i<m;i++)
    {
        vector<int> edge(3);
        for(int j=0;j<3;j++) cin>>edge[j];
        t.push_back(edge);
    }
    int src,dst; cin>>src>>dst;
    Solution obj;
    cout<<obj.findCheapestPrice(n,t,src,dst,k)<<'\n';
}