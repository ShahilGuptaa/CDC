// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> f(vector<vector<string>> logs)
{
  int n = logs.size();
  map<string, map<int, int>> mp; // string,price,quantity
  vector<int> ans;
  for (int i = 0; i < logs.size(); i++)
  {
    if (logs[i][0] == "supply")
    {
      mp[logs[i][1]].insert({stoi(logs[i][3]), stoi(logs[i][2])});
    }
    else if (logs[i][0] == "sell")
    {
      ans.push_back(stoi(logs[i][2]) * (mp[logs[i][1]].begin()->first));
      mp[logs[i][1]].begin()->second -= stoi(logs[i][2]);
      if (mp[logs[i][1]].begin()->second == 0)
      {
        mp[logs[i][1]].erase(mp[logs[i][1]].begin());
      }
    }
    else if (logs[i][0] == "upgrade")
    {
      mp[logs[i][1]].insert({stoi(logs[i][4]), stoi(logs[i][2])});
      if (mp[logs[i][1]].find(stoi(logs[i][3])) != mp[logs[i][1]].end())
      {
        mp[logs[i][1]][stoi(logs[i][3])] -= stoi(logs[i][2]);
      }
    }
  }
  return ans;
}
int main()
{
  // Write C++ code here
  vector<vector<string>> commands = {{"supply", "r1", "2", "100"}, {"supply", "r2", "3", "60"}, {"sell", "r1", "1"}, {"sell", "r2", "1"}, {"upgrade", "r2", "1", "60", "100"}, {"sell", "r2", "1"}, {"sell", "r2", "1"}};
  vector<int> ans = f(commands);
  for (auto it : ans)
    cout << it << " ";
  return 0;
}