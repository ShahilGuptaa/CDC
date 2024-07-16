// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int extractnum(string s)
{
  string num = "";
  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (s[i] >= 48 && s[i] <= 57)
      num += s[i];
  }
  reverse(num.begin(), num.end());
  return stoi(num);
}
string extractname(string s)
{
  string num = "";
  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (s[i] >= 65 && s[i] <= 90 || s[i] >= 97 && s[i] < 122)
      num += s[i];
  }
  reverse(num.begin(), num.end());
  return num;
}
bool comp(const pair<string, int> &a, const pair<string, int> &b)
{
  return a.second > b.second;
}

void sortmp(unordered_map<string, int> &mp)
{
  vector<pair<string, int>> vec;
  for (auto it : mp)
  {
    vec.push_back({it.first, it.second});
  }
  mp.clear();
  sort(vec.begin(), vec.end(), comp);
  for (auto it : vec)
  {
    mp.insert({it.first, it.second});
  }
}
vector<string> f(vector<vector<string>> queries)
{
  vector<string> ans;
  unordered_map<string, int> mp;
  unordered_set<string> used;

  for (int i = 0; i < queries.size(); i++)
  {
    for (int j = 0; j < queries[0].size(); j++)
    {
      if (used.find(extractname(queries[i][j])) != used.end() && mp.find(extractname(queries[i][j])) == mp.end())
        continue;
      else
        mp[extractname(queries[i][j])] = extractnum(queries[i][j]);
    }
    sortmp(mp);
    used.insert(mp.begin()->first);
    mp.erase(mp.begin()->first);
  }
  for (auto it : used)
    ans.push_back(it);
  return ans;
}

int main()
{
  // Write C++ code here
  vector<vector<string>> s = {{"h 164", "g 155", "d 147", "j 160"}, {"j 152", "g 173", "h 190", "d 132"}, {"h 195", "g 180", "j 153", "d 136"}, {"h 125", "g 130", "j 110", "d 156"}};
  for (auto it : f(s))
    cout << it << " ";
  return 0;
}