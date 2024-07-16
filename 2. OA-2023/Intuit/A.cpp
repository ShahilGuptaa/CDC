#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

string longestCommonPrefix(vector<string>& S) {
        if (S.size() == 0) return "";
        std::string prefix = S[0];
 
        for (int i = 1; i < S.size(); ++i) {
          std::string s = S[i];
          if (s.size() == 0 || prefix == "") return "";
          prefix = prefix.substr(0, std::min(prefix.size(), s.size()) );
            
            for (int k = 0; k < s.size() && k < prefix.size(); ++k) {
                if (s[k] != prefix[k]) {
                    prefix = prefix.substr(0, k);
                    break;
                }
            }
        }
        return prefix;
    }

void solve()
{
    lli n,m;cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    vector<string> fin = grid;
    for(int j=0;j<m;j++)
    {
        string temp="";
        for(int i=0;i<n;i++)
        {
            temp.push_back(grid[i][j]);
        }
        fin.push_back(temp);
    }
    int q; cin>>q;
    while(q--)
    {
        string craving; 
        cin>>craving;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;cin>>t;while(t--)
    solve();
}