#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

bool check(int mid)
{
    
}

void solve()
{
    lli n,p;cin>>n>>p;
    vector<vector<int>> v(n,vector<int>(p));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            cin>>v[i][j];
        }
    }

    lli m,k;cin>>m>>k;
    vector<vector<int>> s(m,vector<int>(k));
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<k;j++)
        {
            cin>>s[i][j];
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}