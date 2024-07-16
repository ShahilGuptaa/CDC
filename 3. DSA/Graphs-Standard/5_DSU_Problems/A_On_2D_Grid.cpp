// https://leetcode.com/problems/making-a-large-island/
#include<bits/stdc++.h>
using namespace std;
using ii = pair<int,int>;

//union find by Size
class Solution {
public:
    int n,m;
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int check(int x,int y){
        if(x>=0 && y>=0 && x<n && y<m) return 1;
        else return 0;
    }
    ii par[500][500];
    int size[500][500];
    ii find(ii x){
        if(par[x.first][x.second]==x) return x;
        return ( par[x.first][x.second]=find(par[x.first][x.second]) );
    }
    void unite(ii x, ii y){
        ii rx = find(x), ry = find(y);
        if(size[rx.first][rx.second]<size[ry.first][ry.second]) swap(rx,ry);

        size[rx.first][rx.second] += size[ry.first][ry.second];
        par[ry.first][ry.second] = rx;
    }
    int findSize(ii x){
        ii rx = find(x);
        return size[rx.first][rx.second];
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        n = grid.size(), m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                par[i][j] = {i,j};
                if(grid[i][j]) size[i][j] = 1;
                else size[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                {
                    for(int k=0;k<4;k++)
                    {
                        int nx = i+dx[k],ny=j+dy[k];
                        if( check(nx,ny) && grid[nx][ny] && find({nx,ny})!=find({i,j}) )
                        {
                            unite({nx,ny},{i,j});
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                if(!grid[i][j])
                {
                    set<ii> s;
                    for(int k=0;k<4;k++)
                    {
                        int nx = i+dx[k],ny=j+dy[k];
                        if(check(nx,ny) && grid[nx][ny]==1)
                        {
                            s.insert(find({nx,ny}));
                        }
                    }
                    int temp = 1;
                    for(auto k: s){
                        temp += findSize(k);
                    }
                    ans = max(ans,temp);
                }
                else
                {
                    ans = max(ans,findSize({i,j}));
                }
            }
        }
        return ans;
    }
};