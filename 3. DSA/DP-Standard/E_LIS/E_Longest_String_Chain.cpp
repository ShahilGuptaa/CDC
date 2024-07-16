#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int check(string s,string t){
        if(t.size()-s.size()!=1) return 0;
        int i=0;
        for(i=0;i<s.size();i++){
            if(s[i]!=t[i]) break;
        }
        for(;i<s.size();i++){
            if(s[i]!=t[i+1]) return 0;
        }
        return 1;
    }
    //recursive solution
    int rec(int level,int last,vector<string>& words,vector<vector<int>> &dp){
        if(level==words.size()+1) return 0;

        if(dp[level][last]!=-1) return dp[level][last];

        int ans = rec(level+1,last,words,dp);
        if(last==0) ans = max(ans,1+rec(level+1,level,words,dp));
        else{
            if(check(words[last-1],words[level-1])) ans = max(ans,1+rec(level+1,level,words,dp));
        }
        return dp[level][last]=ans;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string s, string t){
            return (s.size()<t.size());
        });
        int n = words.size();
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));

        //bottom up
        for(int i=n+1;i>=1;i--){
            for(int j=n+1;j>=1;j--){
                if(i==n+1) dp[i][j]=0;
                if(i<=j) dp[i][j] = 0;
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=0;j<i;j++){
                dp[i][j] = dp[i+1][j];
                if(j==0) dp[i][j] = max(dp[i][j],1+dp[i+1][i]);
                else if(check(words[j-1],words[i-1])){
                    dp[i][j] = max(dp[i][j],1+dp[i+1][i]);
                }
            }
        }
        return dp[1][0];
    }
};

int main()
{
    vector<string> words = {"xbc","pcxbcf","xb","cxbc","pcxbc"};
    Solution obj;
    cout<<obj.longestStrChain(words)<<'\n';
}
