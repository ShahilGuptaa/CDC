// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

string f(vector<int> arr, vector<string> queries)
{

  map<int, set<int>> mp;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] == 0)
      mp[0].insert(i);
    else
      mp[1].insert(i);
  }
  for (auto q : queries)
  {
    if (q == "L" && mp.find(0) != mp.end())
    {
      auto it = mp[0].begin();
      mp[0].erase(mp[0].begin());
      mp[1].insert(*it);
    }
    else
    {
      int pos = stoi(q.substr(1));
      mp[0].insert(pos);
      if (mp[1].find(pos) != mp[1].end())
        mp[1].erase(pos);
    }
  }
  vector<int> ans(arr.size(), 0);
  for (auto it : mp[0])
  {
    ans[it] = 0;
  }
  for (auto it : mp[1])
  {
    ans[it] = 1;
  }
  string anss = "";
  for (auto e : ans)
    anss += to_string(e);
  return anss;
}

int main()
{
  // Write C++ code here
  vector<int> arr = {0, 0, 0, 0, 0, 0, 0, 0};
  vector<string> op = {"L", "L", "C0", "L", "C3", "L", "L", "L", "L", "C6", "L", "C3"};
  cout << f(arr, op);

  return 0;
}