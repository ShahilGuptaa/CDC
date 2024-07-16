// Online C++ compiler to run C++ program online
#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;

vector<int> f(int r, vector<vector<int>> queries)
{
  map<int, set<int>> mp1;
  map<int, int> mp2;
  // mp1->color,{indexes}, mp2->index,color
  vector<int> ans;
  for (auto q : queries)
  {
    mp1[q[1]].insert(q[0]);
    if (mp2.find(q[0]) != mp2.end())
    {
      int temp = mp2[q[0]];
      mp2[q[0]] = q[1];
      mp1[temp].erase(q[0]);
      if (mp1[temp].size() == 0)
        mp1.erase(temp);
    }
    else
    {
      mp2[q[0]] = q[1];
    }
    ans.push_back(mp1.size());
  }
  return ans;
}

int main()
{
  vector<vector<int>> q = {{1, 2}, {3, 5}, {3, 1}, {3, 2}, {4, 5}, {6, 1}};
  for (auto it : f(8, q))
  {
    cout << it << " ";
  }
  return 0;
}