// https://www.geeksforgeeks.org/problems/number-of-islands/1

#include <bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
class Solution {
  public:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,-1,1};
      
    ii par[102][102];
    int rank[102][102];
    
    ii find(ii x){
        if(par[x.first][x.second]==x) return x;
        return ( par[x.first][x.second]=find(par[x.first][x.second]) ); //path compression
    }
    void unite(ii x,ii y){
        ii rx = find(x), ry = find(y);
        if( rank[rx.first][rx.second]<rank[ry.first][ry.second] ) swap(rx,ry);
        if( rank[rx.first][rx.second]==rank[ry.first][ry.second] ) rank[rx.first][rx.second]++;
        par[ry.first][ry.second] = rx;
    }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &ops) 
    {
        int is = 0;
        vector<int> ans;
        vector<vector<int>> grid(n,vector<int>(m,0));
        //Initialization
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                par[i][j] = {i,j}; rank[i][j] = 0;
            }
        }
        for(int i=0;i<ops.size();i++)
        {
            int r = ops[i][0], c = ops[i][1];
            if(grid[r][c]){
                ans.push_back(is);
                continue;
            }
            grid[r][c] = 1;
            set<ii> roots;
            for(int k=0;k<4;k++)
            {
                int nx = r + dx[k], ny = c + dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny])
                {
                    roots.insert(find({nx,ny}));
                }
            }
            
            if(roots.size()==0){
                is++;
            }else{
                for(auto k: roots){
                    unite(k,{r,c});
                }
                is -= (roots.size()-1);
            }
            ans.push_back(is);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends