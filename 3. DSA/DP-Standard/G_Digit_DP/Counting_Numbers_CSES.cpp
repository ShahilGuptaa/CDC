#include<bits/stdc++.h>
using namespace std;

//https://cses.fi/problemset/task/2220/

string l,r;
int n;
long long int dp[20][2][2][10][2];

long long int rec(int level,int lti,int hti, int last, int lz) //lz = leading zeros
{
    if(level==n) return 1;
    
    if(last!=-1 && dp[level][lti][hti][last][lz]!=-1) return dp[level][lti][hti][last][lz];

    long long int ans = 0;
    int lo = 0, hi = 9;
    if(lti) lo = l[level]-'0';
    if(hti) hi = r[level]-'0';

    for(int i=lo;i<=hi;i++)
    {
        int nlti = lti, nhti = hti, nlz = lz;
        if(i!=lo) nlti = 0;
        if(i!=hi) nhti = 0;
        if(i!=0) nlz = 0;
        
        if(lz) {
            ans += rec(level+1,nlti,nhti,i,nlz);
        }else{
            if(i!=last) ans += rec(level+1,nlti,nhti,i,nlz);
        }
    }
    if(last==-1) return ans;
    else return dp[level][lti][hti][last][lz] = ans;
}

void solve()
{
    cin>>l>>r;
    n = r.size();
    
    //making l and r of the same length by padding '0's
    int diff = r.size() - l.size();
    string pre = "";
    for(int i=0;i<diff;i++){
        pre.push_back('0');
    }
    l = pre + l;

    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1,1,-1,1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}