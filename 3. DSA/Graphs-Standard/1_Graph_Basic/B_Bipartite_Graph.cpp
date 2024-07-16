#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> g;
    vector<int> col;
    void dfs(int nn, int c){
        col[nn] = c;
        for(auto v:g[nn]){
            if(col[v]==-1){
                dfs(v,(!c));
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        g = graph;
        col.assign(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                dfs(i,1);
            }
        }
        for(auto i=0;i<n;i++){
            for(auto j: g[i]){
                if(col[i]==col[j]){
                    return 0;
                }
            }
        }
        return 1;
    }
};