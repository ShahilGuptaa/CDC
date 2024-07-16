#include<bits/stdc++.h>
using namespace std;
using lli = long long int;

//Minimize the consecutive diff^2 by inserting 1 element

void solve()
{
    lli n;cin>>n;
    vector<lli> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    lli sum = 0;
    lli ma = -1;
    lli a,b;
    for(int i=1;i<n;i++)
    {
        lli curr = (v[i]-v[i-1])*(v[i]-v[i-1]);
        sum += curr;
        if(curr>ma)
        {
            ma = curr;
            a = v[i];
            b = v[i-1];
        }
    }
    sum -= ma;
    lli ele_in = (a+b)/2;
    lli ele_in2 = ele_in + 1;
    lli ele_in3 = ele_in - 1;

    lli sum1 = sum + (a-ele_in)*(a-ele_in) + (b-ele_in)*(b-ele_in);
    lli sum2 = sum + (a-ele_in2)*(a-ele_in2) + (b-ele_in2)*(b-ele_in2);
    lli sum3 = sum + (a-ele_in3)*(a-ele_in3) + (b-ele_in3)*(b-ele_in3);
    cout<<min({sum1,sum2,sum3})<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}