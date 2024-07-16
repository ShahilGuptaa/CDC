#include <bits/stdc++.h>
using namespace std;
unordered_map<char, vector<int>> m;
int main()
{
    string s, pass;
    cin >> s >> pass;
    deque<char> dq;
    for(int i=0;i<s.size();i++)
    {
        dq.push_back(s[i]);
    }
    int ans = 0;
    for(int i=0;i<pass.size();i++)
    {
        deque<char> forward;
        deque<char> backward;
        forward = dq;
        backward = dq;

        int fops = 0,bops = 0;
        while(forward.front()!=pass[i])
        {
            char temp = forward.front();
            forward.pop_front();
            forward.push_back(temp);
            fops++;
        }
        fops++; //locking

        while(backward.front()!=pass[i])
        {
            char temp = backward.back();
            backward.pop_back();
            backward.push_front(temp);
            bops++;
        }
        bops++;

        if(fops<bops)
        {
            ans += fops;
            dq = forward;
        }
        else
        {
            ans += bops;
            dq = backward;
        }
    }
    cout<<ans<<'\n';
}