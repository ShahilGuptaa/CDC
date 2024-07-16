#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int getSmallestArea(vector<vector<int>> grid)
{
    lli n,m;
    n = grid.size();
    m = grid[0].size();
    int maxi=-1,maxj=-1;
    int mini=n,minj=m;
    int is1pre = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                is1pre = 1;
                maxi = max(maxi,i);
                maxj = max(maxj,j);
                mini = min(mini,i);
                minj = min(minj,j);
            }
        }
    }
    if(is1pre==0)
    {
        return 0;
    }
    int l = (maxi-mini)+1;
    int b = (maxj-minj)+1;
    return (l*b);
}
