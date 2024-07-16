// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> grid, queue<pair<int, int>> q, vector<vector<bool>> &vis)
{
  int n = grid.size();
  int m = grid[0].size();
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  while (q.size() != 0)
  {
    auto p = q.front();
    q.pop();
    int x = p.first;
    int y = p.second;
    vis[x][y] = true;
    for (int t = 0; t < 4; t++)
    {
      int newx = x + dir[t][0];
      int newy = y + dir[t][1];
      if (newx >= 0 && newy >= 0 && newx < n && newy < m && !vis[newx][newy] && grid[newx][newy] == grid[x][y])
      {
        vis[newx][newy] = true;
        q.push({newx, newy});
      }
    }
  }
}

void editmatrix(vector<vector<int>> &grid)
{

  int n = grid.size();
  int m = grid[0].size();
  for (int j = 0; j < m; j++)
  {
    queue<int> q;
    int cntz = 0;
    for (int i = 0; i < n; i++)
    {
      if (grid[i][j] == 0)
        cntz++;
      else
        q.push(grid[i][j]);
    }
    for (int i = 0; i < cntz; i++)
    {
      grid[i][j] = 0;
    }
    for (int i = cntz; i < n; i++)
    {
      grid[i][j] = q.front();
      q.pop();
    }
  }
}
void f(vector<vector<int>> board)
{
  int n = board.size();
  int m = board[0].size();
  int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // first check for eligible bubbles
      int cntsame = 0;
      vector<vector<bool>> vis(n, vector<bool>(m, false));
      vis[i][j] = true;
      for (int t = 0; t < 4; t++)
      {
        int newx = i + dir[t][0];
        int newy = j + dir[t][1];
        if (newx >= 0 && newy >= 0 && newx < n && newy < m && !vis[newx][newy])
        {
          vis[newx][newy] = true;
          if (board[i][j] == board[newx][newy])
            cntsame++;
        }
      }
      if (cntsame >= 2)
      {
        // eligible bubbles push to queue
        q.push({i, j});
      }
    }
  }
  vector<vector<bool>> vis2(n, vector<bool>(m, false));
  bfs(board, q, vis2);

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vis2[i][j] == 1)
      {
        board[i][j] = 0;
      }
    }
  }
  editmatrix(board);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  // Write C++ code here
  // vector<vector<int>>grid={{3,1,2,1},{1,1,1,4},{3,1,2,2},{3,3,3,4}};
  vector<vector<int>> grid = {{3, 1, 2, 1}, {1, 1, 1, 4}, {3, 1, 2, 2}, {3, 3, 2, 4}};

  f(grid);
  return 0;
}