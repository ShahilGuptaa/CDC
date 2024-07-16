#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<int,int>;
#define F first
#define S second
const lli mod = 1000000007;

//only distance array can do the job, visited is not required

int n,m,x;
vector<vector<int>> vis;
vector<vector<int>> dis;

int isSquare(int x)
{
    for(int i=0;i*i<=x;i++)
    {
        if(i*i==x) return i;
    }
    return -1;
}

bool inside(int x,int y)
{
    if(x>=0 && x<n && y>=0 && y<m) return 1;
    else return 0;
}

bool checkX(ii cur,ii tak)
{
    if ((cur.F - tak.F)*(cur.F-tak.F) + (cur.S - tak.S)*(cur.S-tak.S) == x*x) return 1;
    else return 0;
}

void bfs(ii st)
{
    vis[st.first][st.second]=1;
    dis[st.first][st.second]=0;
    queue<ii> q;
    q.push(st);

    while(!q.empty())
    {
        ii curr = q.front();
        q.pop();
        int dx,dy;
        for(int i=-x;i<=x;i++)
        {
            dx = i;
            dy = (x*x - dx*dx);
            if(isSquare(dy)!=-1)
            {
                dy = isSquare(dy);
                ii neigh = {curr.first+dx,curr.second + dy};
                int x = curr.first + dx;
                int y = curr.second + dy;
                if(checkX(curr,neigh) && inside(x,y) && !vis[x][y])
                {
                    q.push(neigh);
                    vis[x][y]=1;
                    dis[x][y] = dis[curr.F][curr.S] + 1; //relaxation
                }
                neigh = {curr.first+dx,curr.second - dy};
                x = curr.first + dx;
                y = curr.second - dy;
                if(checkX(curr,neigh) && inside(x,y) && !vis[x][y])
                {
                    q.push(neigh);
                    vis[x][y]=1;
                    dis[x][y] = dis[curr.F][curr.S] + 1; //relaxation
                }
            }
        }
               
    }
}

void solve()
{
    cin>>n>>m>>x;
    vis.assign(n,vector<int>(m,0));
    dis.assign(n,vector<int>(m,1e9));

    ii st,end;
    cin>>st.F>>st.S;
    st.F--; st.S--;
    cin>>end.F>>end.S;
    end.F--;end.S--;
    bfs(st);
    cout<<dis[end.F][end.S]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t = 1;//cin>>t;
    while(t--)
    {
        solve();
    }
}