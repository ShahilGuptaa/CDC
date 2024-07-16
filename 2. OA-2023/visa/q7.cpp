// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int f(vector<int> a2b, vector<int> b2a, int trips)
{
  bool useA = false;
  set<int> a2, b2;
  for (int i = 0; i < a2b.size(); i++)
  {
    a2.insert(a2b[i]);
    b2.insert(b2a[i]);
  }
  int t = a2b[0] + 100;
  int ans = 0;
  int cnt = 0;
  while (cnt != trips)
  {
    ans = 0;
    if (!useA)
    {
      auto it = lower_bound(b2.begin(), b2.end(), t);
      useA = true;
      ans += (*it) + 100;
      t = ans;
      cnt++;
    }
    else
    {
      auto it = lower_bound(a2.begin(), a2.end(), t);
      useA = false;
      t = (*it) + 100;
    }
  }
  return ans;
}

int main()
{
  // Write C++ code here
  //   vector<int> a2b = {109, 200, 500, 700, 1000};
  //   vector<int> b2a = {99, 210, 600, 810, 900};
  //   vector<int>a2b={0,200,500};
  //   vector<int>b2a={99,210,450};
  vector<int> a2b = {5, 206};
  vector<int> b2a = {105, 306};

  cout << f(a2b, b2a, 2);

  return 0;
}
