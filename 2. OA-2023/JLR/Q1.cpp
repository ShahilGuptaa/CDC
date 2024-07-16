#include <bits/stdc++.h>
using namespace std;

void printMaxNum(int num)
{
    string s = to_string(num);
    int n = s.length();
    
    vector<string> ans;
    for(int i=0;i<n;i++)
    {
        map<char,int> temp;
        string p="";
        for(int j=0;j<i;j++){
            p.push_back(s[j]);
        }
        for(int j=i;j<n;j++){
            temp[s[j]]++;
        }
        auto itt = temp.upper_bound(s[i]);
        if(itt !=temp.end())
        {
            p.push_back(itt->first);
            temp[itt->first]--;
            if(temp[itt->first]==0) temp.erase(itt->first);
        }
        else continue;

        for(int j=i+1;j<n;j++){
            auto it = temp.begin();
            if(it==temp.end()) it--;

            char c = it->first;
            p.push_back(c);

            temp[it->first]--;
            if(temp[it->first]==0) temp.erase(it->first);
        }
        ans.push_back(p);
    }
    if(ans.size()==0)
    {
        cout<<"-1\n";
        return;
    }
    sort(ans.begin(),ans.end());
    cout<<ans[0]<<'\n';
}
int main()
{
    int N; cin>>N;
    printMaxNum(N);
    return 0;
}