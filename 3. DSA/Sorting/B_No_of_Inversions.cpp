#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

/*
Inversion Count for an array indicates – how far (or close) the array is from being sorted. 
If the array is already sorted, then the inversion count is 0, 
but if the array is sorted in reverse order, the inversion count is the maximum.
*/

int cnt_inversion_pairs;
void merge(int l,int m, int h, int arr[]){
    int temp[h-l+1];
    int i = l, j = m+1;
    int p = 0;
    while(i<=m && j<=h){
        if(arr[i]<=arr[j]){
            temp[p] = arr[i];
            i++;
        }else{
            cnt_inversion_pairs += (m-i+1);
            temp[p] = arr[j];
            j++;
        }
        p++;
    }
    while(i<=m){
        temp[p] = arr[i];
        i++; p++;
    }
    while(j<=h){
        temp[p] = arr[j];
        j++; p++;
    }
    for(int i=l;i<=h;i++) arr[i] = temp[i-l];
    return;
}
void mergeSort(int l,int h,int arr[]){
    if(l>=h) return;

    int mid = (l+h)/2;
    mergeSort(l,mid,arr);
    mergeSort(mid+1,h,arr);
    merge(l,mid,h,arr);
    return;
}
void solve()
{
    cnt_inversion_pairs = 0;
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    mergeSort(0,n-1,arr);
    for(int i=0;i<n;i++) cout<<arr[i]<<' ';
    cout<<'\n';
    cout<<cnt_inversion_pairs<<"\n\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}