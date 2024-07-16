//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	    void print_all(int i,int j,string req,vector<string> &ans,string &s1, string &s2,vector<vector<int>> &dp){
	        int n = s1.size();
	        int m = s2.size();
	        if(i==0 || j==0){
	            ans.push_back(req);
	            return;
	        }
	        if(s1[i-1]==s2[j-1]){
	            req.push_back(s1[i-1]);
	            print_all(i-1,j-1,req,ans,s1,s2,dp);
	        }
	        else{
	            if(dp[i-1][j]>dp[i][j-1]){
	                print_all(i-1,j,req,ans,s1,s2,dp);
	            }
	            else if(dp[i-1][j]==dp[i][j-1]){
	                print_all(i-1,j,req,ans,s1,s2,dp);
	                print_all(i,j-1,req,ans,s1,s2,dp);
	            }
	            else{
	                print_all(i,j-1,req,ans,s1,s2,dp);
	            }
	        }
	    }
		vector<string> all_longest_common_subsequences(string s1, string s2)
		{
		    int n = s1.size(),m = s2.size();
		    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=m;j++){
		            if(i*j==0) dp[i][j] = 0;
		            else if(s1[i-1]==s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
		            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		        }
		    }
	
		    vector<string> ans;
		    string temp;
		    print_all(n,m,temp,ans,s1,s2,dp);

            //Removing duplicates
		    set<string> p;
		    for(int i=0;i<ans.size();i++){
		        reverse(ans[i].begin(),ans[i].end());
		        p.insert(ans[i]);
		    }
		    
            //creating the final answer array
		    vector<string> fin;
		    for(auto it: p){
		        fin.push_back(it);
		    }
		    return fin;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends