#include <bits/stdc++.h>
using ll =  long long int;
ll mod= 1000000007;
using namespace std;

ll binary_exponentiation(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2==1)
        {
            ans=(ans*a)%mod; //typecasting ans to long long int
        }
        a = (a*a)%mod;
        b/=2;
    }
    return ans;
}

void print(vector<ll> v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<'\n';
    }
}

signed main() {
    ll n, a, b;
    cin >> n >> a >> b;
    multiset<ll> s; // Changed long long int to ll
    for (int i = 0; i < n; i++) {
        ll num; // Changed int to ll
        cin >> num;
        s.insert(num);
    }

    while (b > 0 && a > 1) {
        ll least = *s.begin();
        s.erase(s.begin());

        auto it = s.lower_bound(least);
        ll diff;
        if (it != s.end()) diff = (*it - least);
        else diff = b;

        if (diff <= b) {
            b -= diff;
            s.insert((least * binary_exponentiation(a, diff)) % mod);
        } else {
            s.insert((least * binary_exponentiation(a, b)) % mod);
            break;
        }
    }
    
    // Corrected the sort function
    vector<ll> num_req(s.begin(), s.end());
    sort(num_req.begin(), num_req.end());

    print(num_req);
}