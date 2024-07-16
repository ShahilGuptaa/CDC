#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

//Given an array Find the longest subsequence suct that AND of all the numbers in the susequence is non-zero
int getMaxLength(vector<int> arr)
{
    int n = arr.size();
    vector<lli> v(n);
    vector<lli> s(33);
    for(int i=0;i<n;i++)
    {
        v[i] = arr[i];
        for(int j=0;j<=32;j++)
        {
            if(v[i]&(1ll<<j))
            {
                s[j]++;
            }
        }
    }
    sort(s.begin(),s.end());
    return s[32];
}

int main()
{
    lli n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<getMaxLength(v)<<'\n';
}