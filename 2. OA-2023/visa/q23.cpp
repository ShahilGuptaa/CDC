// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;
bool checknum(int n)
{
  unordered_map<int, int> mp;
  while (n > 0)
  {
    int last = n % 10;
    mp[last]++;
    n = n / 10;
  }
  for (auto it : mp)
  {
    if (it.second > 1)
      return false;
  }
  return true;
}

int solve(int l, int r)
{
  set<int> set;
  for (int i = 100; i <= 999; i++)
  {
    if (checknum(i))
      set.insert(i);
  }
  int cnt = 0;
  for (int i = l; i <= r; i++)
  {
    if (set.find(i) != set.end())
      cnt++;
  }
  return cnt;
}

int main()
{
  // Write C++ code here
  int l, r;
  cin >> l >> r;
  cout << solve(l, r);

  return 0;
}