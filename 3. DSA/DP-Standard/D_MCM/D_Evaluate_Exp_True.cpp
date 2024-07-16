#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
//https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1

lli dp[502][502][2];

int val(char c){
    if(c=='T') return 1;
    else if(c=='F') return 0;
}

lli rec(int i,int j,int flag,string &s){ //flag = 1 > gives no. of ways to get true
                                         //flag = 0 > gives no. of ways to get flase

    //Base case
    if(i==j){
        if(val(s[i])) {
            return flag;
        }
        else return (!flag);
    }
    //cache check
    if(dp[i][j][flag]!=-1) return dp[i][j][flag];

    //transitions
    lli ans = 0;
    for(int k = i+1;k<j;k+=2){
        char op = s[k];
        lli lt = rec(i,k-1,1,s);
        lli lf = rec(i,k-1,0,s);
        lli rt = rec(k+1,j,1,s);
        lli rf = rec(k+1,j,0,s);
        if(flag){
            if(op=='&') {
                ans += lt*rt;
            }
            else if(op=='^') {
                ans += lf*rt + lt*rf;
            }
            else{
                ans += lt*rt;
                ans += lf*rt + lt*rf;
            }
        }
        else{
           if(op=='&') {
                ans += lf*rt + lt*rf + lf*rf;
            }
            else if(op=='^') {
                ans += lt*rt + lf*rf;
            }
            else{
                ans += lf*rf;
            } 
        }
    }

    //save and return
    return dp[i][j][flag] = ans;
}

void solve()
{
    string s; cin>>s;
    int n = s.size();
    memset(dp,-1,sizeof(dp));
    //we can only point to an operator
    cout<<rec(0,n-1,1,s)<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
}