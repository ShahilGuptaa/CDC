#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int n;
int p,f,u,d;
bool is_inside(int x)
{
    if(x<1 || x>n) return 0;
    return 1;
}

vector<lli> dist;
void bfs(int st)
{
    queue<int> q;
    q.push(st);
    dist[st] = 0;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        int neigh1 = curr+u;
        int neigh2 = curr-d;

        if(is_inside(neigh1))
        {
            if(dist[neigh1]>dist[curr]+1)
            {
                dist[neigh1]=dist[curr]+1;
                q.push(neigh1);
            }
        }
        if(is_inside(neigh2))
        {
            if(dist[neigh2]>dist[curr]+1)
            {
                dist[neigh2]=dist[curr]+1;
                q.push(neigh2);
            }
        }
    }
}

void solve()
{
    cin>>n>>p>>f>>u>>d;
    dist.assign(n+1,INF);

    bfs(p);

    if(dist[f]==INF)
    {
        cout<<"-1\n";
    }else{
        cout<<dist[f]<<'\n';
    }

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}