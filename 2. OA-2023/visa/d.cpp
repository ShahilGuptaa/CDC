#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli,lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;
bool ismatch(int x, int y, vector<vector<int>> board, vector<vector<char>> pattern)
{
      unordered_map<char, int> curr;
      set<int> coord;
      for (int i = 0; i < pattern.size(); i++)
    {
            for (int j = 0; j < pattern[0].size(); j++)
        {
                  if (isalpha(pattern[i][j]))
            {
                        if (curr.find(pattern[i][j]) == curr.end())
                {
                              curr[pattern[i][j]] = board[x + i][y + j] bool ismatch(int x, int y, vector<vector<int>> board, vector<vector<char>> pattern)
                    {
                          unordered_map<char, int> curr;
                          set<int> coord;
                          for (int i = 0; i < pattern.size(); i++)
                        {
                                for (int j = 0; j < pattern[0].size(); j++)
                            {
                                      if (isalpha(pattern[i][j]))
                                {
                                            if (curr.find(pattern[i][j]) == curr.end())
                                    {
                                                  curr[pattern[i][j]] = board[x + i][y + j];
                                                  if (coord.find(board[x + i][y + j]) == coord.end())                      coord.insert(board[x + i][y + j]);
                                                  else return false;
                                               
                                    }
                                            else if (curr[pattern[i][j]] != board[i][j])
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
                    }
                    vector<int> solution(vector<vector<int>> board, vector<vector<char>> pattern)
                    {
                        vector<int> e = {-1, -1};
                        for (int x = 0; x < board.size() - pattern.size() + 1; x++)
                        {
                              for (int y = 0; y < board[0].size() - pattern[0].size() + 1; x++)
                            {
                                  unordered_map<char, int> sub;
                                  if (ismatch(x, y, board, pattern))
                                {
                                        return {x, y};
                                     
                                }
                            }
                        }
                        return e;
                    };
                              if (coord.find(board[x + i][y + j]) == coord.end())                      coord.insert(board[x + i][y + j]);
                              else return false;
                           
                }
                        else if (curr[pattern[i][j]] != board[i][j])
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
}
vector<int> solution(vector<vector<int>> board, vector<vector<char>> pattern)
{
    vector<int> e = {-1, -1};
    for (int x = 0; x < board.size() - pattern.size() + 1; x++)
    {
          for (int y = 0; y < board[0].size() - pattern[0].size() + 1; x++)
        {
              unordered_map<char, int> sub;
              if (ismatch(x, y, board, pattern))
            {
                    return {x, y};
                 
            }
        }
    }
    return e;
}