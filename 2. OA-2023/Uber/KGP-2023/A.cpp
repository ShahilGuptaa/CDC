#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int solve(vector<int> numbers,int threshold)
{
    int n = numbers.size();
    int t = threshold;
    vector<int> a(n);
    for(int i=0;i<n;i++) {
        a[i] = numbers[i];
    }

    for(int i=0;i+2<n;i++)
    {
        if(a[i]>t && a[i+1]>t && a[i+2]>t)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    lli n,t;cin>>n>>t;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    cout<<solve(a,t)<<'\n';
}