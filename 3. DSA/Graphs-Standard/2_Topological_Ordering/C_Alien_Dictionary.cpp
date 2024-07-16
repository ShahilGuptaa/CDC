// https://www.geeksforgeeks.org/problems/alien-dictionary/1

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<vector<int>> g;
    
    void build(string s1,string s2) //s1<s2
    {
        int n = s1.size(),m = s2.size();
        for(int i=0;i<min(n,m);i++){
            if(s1[i]!=s2[i]){
                g[s1[i]-'a'].push_back(s2[i]-'a');
                break;
            }
        }
    }
    string findOrder(string dict[], int N, int K) {
        g.resize(K);
        for(int i=1;i<N;i++)
        {
            build(dict[i-1],dict[i]);
        }
        vector<int> indeg(K,0);
        for(auto i: g){
            for(auto j: i){
                indeg[j]++;
            }
        }
        string ans;
        queue<int> q;
        for(int i=0;i<K;i++) if(indeg[i]==0) q.push(i);
        
        while(!q.empty()){
            int cur = q.front(); q.pop();
            ans.push_back(cur+'a');
            for(auto v:g[cur]){
                indeg[v]--;
                if(indeg[v]==0){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};

string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}