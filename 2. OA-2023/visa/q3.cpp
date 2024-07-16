// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> f(vector<int> houses, vector<int> queries)
{
  int n = houses.size();
  map<int, pair<bool, int>> check;
  check.insert({houses[0], {1, 1}}); // pair contains bool,index of next
  for (int i = 1; i < n; i++)
  {
    if (houses[i] != houses[i - 1] + 1)
    {
      if (i == n - 1) check.insert({houses[i], {1, -1}});
      check.insert({houses[i], {1, i + 1}});
    }
  }
  vector<int> ans;
  int cnt = 0;
  for (auto it : check)
  {
    if (it.first)
      cnt++;
  }
  for (auto q : queries)
  {
    check[q].first = 0;
    if (check[q].second == -1)
    {
      continue;
    }
    if (check[houses[check[q].second]].first == 1)
    {
      ans.push_back(cnt);
    }
    else
    {
      check[houses[check[q].second]].first = 1;
      cnt++;
      ans.push_back(cnt);
    }
  }
  return ans;
}
int main()
{
  int n;cin>>n;
  vector<int> houses(n);
  for(int i=0;i<n;i++) cin>>houses[i];
  
  int q; cin>>q;
  vector<int> queries(q);
  for(int i=0;i<q;i++) cin>>queries[i];
  for (auto it : f(houses, queries))
    cout << it << " ";
  cout << endl;

  return 0;
}