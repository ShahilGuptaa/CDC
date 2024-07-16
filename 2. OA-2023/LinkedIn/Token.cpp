#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

struct tokens{
    set<pair<lli,string>> ids;

    void push(string s, int t){
        ids.insert({t,s});
    }
    void update(string s, int ct,int ttl){
        auto it = ids.upper_bound({0,s});
        if(it->second==s){
            if(it->first <= ct){
                int p = it->first;
                ids.erase(it);
                ids.insert({ct+ttl,s});
            }
        }
    }
    int count(int time){
        int cnt = 0;
        for(auto it: ids){
            if(it.first>=time){
                cnt++;
            }
        }
        return cnt;
    }
};

vector<int> getUnexpiredTokens(int time_to_live, vector<string> &queries)
{
    vector<int> ans;
    struct tokens p;
    int ttl = time_to_live;
    int q = queries.size();
    for(int i=0;i<q;i++)
    {
        string type,tok_id,curr_ti="0";
        string qu = queries[i];
        int l = qu.size();
        int cnts = 0;
        for(int j=0;j<l;j++){
            if(qu[j]==' '){
                cnts++;
            }else if(cnts==0){
                type.push_back(qu[j]);
            }else if(cnts==1){
                tok_id.push_back(qu[j]);
            }else{
                curr_ti.push_back(qu[j]);
            }
        }
            int tim = stoi(curr_ti);
            if(type=="generate"){
                p.push(tok_id,tim+ttl);
            }
            else if(type=="renew"){
                p.update(tok_id,tim,ttl);
            }
            else{
                tim = stoi(tok_id);
                ans.push_back(p.count(tim));
            }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int ttl; cin>>ttl;
    int q; cin>>q;
    vector<string> queries;
    while(q--)
    {
        string type,tok_id, curr_ti;
        cin>>type;
        if(type=="generate" || type=="renew"){
            cin>>tok_id>>curr_ti;
            string fin = type+' ' + tok_id+' '+curr_ti;
            queries.push_back(fin);
        }else{
            cin>>curr_ti;
            string fin = type+' '+curr_ti;
            queries.push_back(fin);
        }
    }
    vector<int> ans = getUnexpiredTokens(ttl,queries);
    for(auto v: ans)
    {
        cout<<v<<' ';
    }
}