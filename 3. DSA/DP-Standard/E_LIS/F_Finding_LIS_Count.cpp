#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

class Solution {
public:
    ii rec(int en, vector<int> &nums,vector<ii> &dp){ //ii = length, frequency of LIS ending at en
        if(en==0) return {1,1};
        if(dp[en].first!=-1) return dp[en];

        ii ans = {1,1};
        for(int i=0;i<en;i++){
            if(nums[i]<nums[en])
            {
                ii temp = rec(i,nums,dp);
                if(ans.first < 1 + temp.first){
                    ans.first = 1+temp.first;
                    ans.second = temp.second;
                }
                else if(ans.first == 1 + temp.first)
                {
                    ans.second += temp.second;
                }
            }
        }
        return dp[en] = ans;
    }
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        int lis = 0,ans = 0;
        vector<ii> dp(n+2,{-1,0});
        for(int i=0;i<n;i++)
        {
            ii temp = rec(i,nums,dp);
            if(temp.first>lis){
                lis = temp.first; ans = temp.second;
            }else if(temp.first==lis){
                ans += temp.second;
            }
        }
        cout<<lis<<'\n';
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    vector<int> nums = {1,3,5,4,7};
    Solution obj;
    cout<<obj.findNumberOfLIS(nums)<<'\n';
}