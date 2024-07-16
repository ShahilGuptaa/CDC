// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
using namespace std;

int getpathsum(int i, int j, vector<vector<int>> grid, vector<vector<bool>> &vis)
{
  int n = grid.size();
  int m = grid[0].size();
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {i, j}});
  vis[i][j] = true;
  int sum = 0;
  int dir[4][2] = {{1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  while (q.size() != 0)
  {
    auto p = q.front();
    q.pop();
    auto pathcord = p.first; // 0 ->means first row of dir vector
    int x = p.second.first;
    int y = p.second.second;
    sum += grid[x][y];

    int newx = x + dir[pathcord][0];
    int newy = y + dir[pathcord][1];

    if (vis[newx][newy] || (newx == 0 && newy == 0) || (newx == n - 1 && newy == m - 1) || (newx == 0 && newy == m - 1) || (newx == n - 1 && newy == 0))
      break;

    if (newy == m - 1)
      pathcord = 1;
    if (newy == 0)
      pathcord = 2;
    if (newx == n - 1)
      pathcord = 3;
    if (newx == 0)
      pathcord = 0;
    q.push({pathcord, {newx, newy}});
    vis[newx][newy] = true;
  }
  return sum;
}

int main()
{
  // Write C++ code here
  vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}, {1, 1, 1, 1, 1, 1}};
  vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));
  cout << getpathsum(2, 0, grid, vis);

  return 0;
}