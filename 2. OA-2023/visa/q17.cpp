#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
bool is_match(int x, int y, vector<vector<char>> pattern, vector<vector<int>> board)
{

  unordered_map<char, int> current_subs;
  set<int> coord;
  for (int i = 0; i < pattern.size(); i++)
  {
    for (int j = 0; j < pattern[0].size(); j++)
    {
      if (isalpha(pattern[i][j]))
      {
        if (current_subs.find(pattern[i][j]) == current_subs.end())
        {
          current_subs[pattern[i][j]] = board[x + i][y + j];
          if (coord.find(board[x + i][y + j]) == coord.end())
            coord.insert(board[x + i][y + j]);
          else
            return false;
        }
        else if (current_subs[pattern[i][j]] != board[x + i][y + j])
        {
          return false;
        }
      }
      else
      {
        if (board[x + i][y + j] != pattern[i][j] - '0')
        {
          return false;
        }
      }
    }
  }
  return true;
};
vector<int> find_submatrix(vector<vector<int>> &board, vector<vector<char>> &pattern)
{

  vector<int> earliest_match = {-1, -1};
  for (int x = 0; x < board.size() - pattern.size() + 1; x++)
  {
    for (int y = 0; y < board[0].size() - pattern[0].size() + 1; y++)
    {
      unordered_map<char, int> substitutions;
      if (is_match(x, y, pattern, board))
      {
        return {x, y};
      }
    }
  }
  return earliest_match;
}

int main()
{
  // vector<vector<int>> board = {
  //     {1, 2, 3, 4},
  //     {5, 6, 7, 8},
  //     {9, 1, 2, 3}
  // };
  // vector<vector<char>> pattern = {
  //     {'A', 'B'},
  //     {'C', 'D'}
  // };
  vector<vector<int>> board = {
      {2, 4, 2, 4, 2},
      {4, 2, 4, 2, 6},
      {1, 4, 2, 5, 3}};
  vector<vector<char>> pattern = {
      {'4', 'c'},
      {'c', 'b'},
      {'n', 'd'}};
  vector<int> result = find_submatrix(board, pattern);
  cout << "Pattern found at coordinates " << result[0] << ", " << result[1] << endl;
  return 0;
}
