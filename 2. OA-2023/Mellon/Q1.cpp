#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
#define F first
#define S second
const lli mod = 1000000007;

lli n,m;
vector<vector<ii>> g;
vector<lli> dis; //sice distance can be 64-bit integer
vector<lli> vis;
vector<int> time_;

//O((V+E)log(E))
void dijktra(int sc)
{
    dis[sc] = 0;
    priority_queue<ii,vector<ii>,greater<ii>> pq;
    pq.push({0,sc});

    while(!pq.empty())
    {
        ii fs = pq.top(); pq.pop();

        if(vis[fs.S]) continue; //optimization otherwise TLE

        vis[fs.S] = 1;
        for(auto v: g[fs.S]){
            lli neigh = v.S;
            lli wt = v.F;
            if(time_[neigh-1]>dis[fs.S]+wt)
            {
                 if(dis[neigh]>dis[fs.S]+wt)
                {
                    dis[neigh] = dis[fs.S]+wt;
                    pq.push({dis[neigh],neigh});
                }
            }
        }
    }
}

void solve()
{
    cin>>n>>m;
    g.resize(n+1);
    dis.assign(n+1,1e18);
    vis.assign(n+1,0);
    time_.resize(n);

    vector<int> from,to,weight;
    for(int i=1;i<=m;i++){
        lli u;
        cin>>u;
        from.push_back(u);
    }
    for(int i=1;i<=m;i++){
        lli v;
        cin>>v;
        to.push_back(v);
    }
    for(int i=1;i<=m;i++){
        lli wt;
        cin>>wt;
        weight.push_back(wt);
    }
    
    for(int i=0;i<n;i++) cin>>time_[i];

    for(int i=1;i<=m;i++)
    {
        g[from[i-1]].push_back({weight[i-1],to[i-1]});
        g[to[i-1]].push_back({weight[i-1],from[i-1]});
    }
    
    vector<int> ans;
    dijktra(1);
    for(int i=1;i<=n;i++){
        if(dis[i]==1e18) ans.push_back(-1);
        else ans.push_back(dis[i]);
        cout<<ans.back()<<' ';
    }


}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}