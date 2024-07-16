#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
const lli INF = 1e18;

void solve()
{
    string s; cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++)
    {
        if(!st.empty())
        {
            if(st.top()==s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }else{
            st.pop();
        }
    }
    cout<<st.size()<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    solve();
}