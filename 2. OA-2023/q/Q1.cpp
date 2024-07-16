#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli mod = 1000000007;

lli n,m;
vector<vector<int>> g;
vector<int> dist; //it will also act as visited

void bfs(int st)
{
    dist[st]=0;
    queue<int> q;
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(auto v : g[cur])
        {
            if(dist[cur]+1< dist[v])
            {
                dist[v] = dist[cur] + 1;
                q.push(v);
            }
        }
    }
}

void prinans(vector<int> res){
    int n = res.size();
    cout<<'[';
    for(int i=0;i<n;i++){
        if(i==n-1) cout<<res[i]<<"]\n";
        else cout<<res[i]<<", ";
    }
}

void solve()
{
    cin>>n;
    m = n-1;
    g.resize(n+1);
    dist.assign(n+1,1e9);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<pair<int,int>> ans;
    int min_val = 1e9;
    for(int i=0;i<n;i++)
    {
        dist.assign(n+1,1e9);
        bfs(i);

        int val = 0;
        for(int j=0;j<n;j++){
            val = max(val,dist[j]);
        }
        min_val = min(min_val,val);

        ans.push_back({val,i});
    }

    vector<int> res;
    for(int i=0;i<n;i++){
        if(ans[i].first==min_val){
            res.push_back(ans[i].second);
        }
    }
    prinans(res);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}