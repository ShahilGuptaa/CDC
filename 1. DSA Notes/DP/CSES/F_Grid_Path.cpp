#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

vector<vector<char>> grid;

int check(int i,int j, int n){
    if(i>=0 && i<n && j>=0 && j<n && grid[i][j]!='*'){
        return 1;
    }else{
        return 0;
    }
}

void solve()
{
    int n;cin>>n;
    grid.resize(n,vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>> ans(n,vector<int>(n));
    for(int j=0;j<n;j++){
        if(check(0,j,n)==0){
            ans[0][j] = 0;
        }else{
            if(j==0) ans[0][j] = 1;
            if(j!=0) ans[0][j] = ans[0][j-1];
        }
    }
    for(int i=1;i<n;i++){
        if(check(i,0,n)) ans[i][0] = ans[i-1][0];
        else ans[i][0] = 0;
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            if(check(i,j,n)){
                ans[i][j] = (ans[i-1][j]%mod + ans[i][j-1]%mod)%mod;
            }else{
                ans[i][j] = 0;
            }
        }
    }
    cout<<ans[n-1][n-1]%mod<<'\n';

    grid.clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}