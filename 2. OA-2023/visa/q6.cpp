#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int getneighbormean(vector<vector<int>> grid, int i, int j, int r, vector<vector<bool>> vis)
{
  int n = grid.size();
  int m = grid[0].size();
  int sum = 0, len = 0;
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {i, j}});
  vis[i][j] = true;
  int dir[8][2] = {{-1, 0}, {-1, -1}, {-1, +1}, {0, -1}, {0, +1}, {1, 0}, {+1, -1}, {+1, +1}};
  while (q.size() != 0)
  {
    auto p = q.front();
    q.pop();
    int cnt = p.first;
    if (cnt == r)
      break;
    int x = p.second.first;
    int y = p.second.second;
    for (int t = 0; t < 8; t++)
    {
      int newr = x + dir[t][0];
      int newc = y + dir[t][1];
      if (newr >= 0 && newc >= 0 && newr < n && newc < m && !vis[newr][newc])
      {
        vis[newr][newc] = 1;
        sum += grid[newr][newc];
        len++;
        q.push({cnt + 1, {newr, newc}});
      }
    }
  }

  return len == 0 ? -1 : (int)sum / (len);
}

int main()
{
  // Write C++ code here
  int n = 3, m = 3, r = 2;
  vector<vector<int>> ans(n, vector<int>(m, 0));
  vector<vector<int>> grid = {{0, 0, 0}, {0, 255, 0}, {0, 0, 0}};
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      vector<vector<bool>> vis(n, vector<bool>(m, false));
      ans[i][j] = (int)(grid[i][j] + getneighbormean(grid, i, j, r, vis)) / 2;
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}