#include <bits/stdc++.h>
using namespace std;

long dominatingXorPairs(vector<int> arr)
{
        long long n, ans=0;
        n= arr.size();
        vector<int> a(32);
        for (int i = 0; i < n; ++i) 
        {
            int x = arr[i], k = 0;
            while(x >= (1 << k)) k++;
            ans += a[k-1];
            a[k-1]++;
        }
        return (1ll*n*(n-1)/2 - ans);
}

int main() {
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<<dominatingXorPairs(arr)<<'\n';
}
