#include<bits/stdc++.h>
using namespace std;

int getMinLength(vector<int> a,int k)
{
    long long int product = 1;
    int count = 1;

    for(int i=0;i<(int)a.size();i++){
        product *= 1ll*a[i];
        if(product>k){
            product = a[i];
            count++;
        }
    }return count;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int n; cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    int k; cin>>k;
    cout<<getMinLength(arr,k)<<'\n';
}