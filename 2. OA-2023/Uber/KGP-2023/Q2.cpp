#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

int findconti(vector<int> arr,int n){
    int res = 0;
    int ans = 0;
    for(int i=0;i<(int)arr.size();i++)
    {
        if(arr[i]==0){
            int temp = 1;
            ans = i;
            for(int j=i+1;j<(int)arr.size();j++){
                if(arr[j]==0){
                    temp++;
                }else{
                    break;
                }
            }
            if(temp>=n){
                return i;
            }
        }
    }
    return -1;
}

void solve()
{
    string s; cin>>s;
    lli t,n,x;cin>>t>>n>>x;

    vector<int> v(t);
    for(int i=0;i<t;i++){
        v[i] = s[i]-'0';
    }
    if(findconti(v,n)==-1)
    {
        cout<<"Tie\n";
        return;
    }
    int time_taken = 0;
    while(findconti(v,n)!=-1)
    {
        int ind = findconti(v,n);
        //cout<<ind<<'\n';
        for(int i=ind;i<ind+n;i++){
            v[i] = 1;
        }
        time_taken++;
    }
    if(time_taken>=x){
        cout<<"Tie\n";
    }
    else if(time_taken%2==0){
        cout<<"Samuel\n";
    }else{
        cout<<"Tina\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}