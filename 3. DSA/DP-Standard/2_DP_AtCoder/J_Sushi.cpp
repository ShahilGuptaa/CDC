#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli N = 301;
//https://youtu.be/XRVCU2Ys9Mk?si=XwCUADfXbM67Yw9R
double dp[N][N][N];
//dp[x][y][z] = x 3s, y 2s, z 1s, (n-x-y-z) 0s

void solve()
{
    lli n;cin>>n;
    int cnt[4] = {0};
    for(int i=0;i<n;i++){
        int x; cin>>x;
        cnt[x]++;
    }
    dp[0][0][0] = 0.0;
    for(int three = 0; three<=n; three++) //no. of indices with #sushis = 3
    {
        for(int two = 0; two<=n; two++)
        {
            for(int one = 0; one<=n; one++)
            {
                int zeros = n - three - two - one;
                if(zeros==n) continue;
                if(one+two+three>n) continue;

                double val = 1.0;
                //pick 3
                if(three>0) val += (1.0*three/n)*dp[three-1][two+1][one];
                if(two>0) val += (1.0*two/n)*dp[three][two-1][one+1];
                if(one>0) val += (1.0*one/n)*dp[three][two][one-1];

                dp[three][two][one] = val/(1-(1.0*zeros/n));
            }
        }
    }
    cout<<setprecision(14);
    cout<<fixed;
    cout<<dp[cnt[3]][cnt[2]][cnt[1]]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}