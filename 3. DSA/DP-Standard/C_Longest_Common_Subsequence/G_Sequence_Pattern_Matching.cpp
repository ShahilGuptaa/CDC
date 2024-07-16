#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

//Is string a subsequnce of string b?
void solve()
{
    string a,b; 
    cin>>a>>b;
    
    int i = 0, j = 0;
    int n = a.size(), m = b.size();

    //O(N+M)
    string com;
    while(i<n){
        char cur = a[i];
        while(j<m){
            if(b[j]==a[i]){
                com.push_back(a[i]);
                j++;
                break;
            }
            j++;
        }
        i++;
    }
    if(com==a){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }
    //Aliter Find LCA(a,b). If LCA(a,b)==len(a) => Ans is True. But here time complexity is n*m
}   

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}