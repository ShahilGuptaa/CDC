// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

unsigned int countSetBits(unsigned int n)
{
  unsigned int count = 0;
  while (n)
  {
    count += n & 1;
    n >>= 1;
  }
  return count;
}

int f(vector<int> arr)
{
  map<int, set<int>> mp;
  for (int i = 0; i < arr.size(); i++)
  {
    mp[countSetBits(arr[i])].insert(i);
  }
  int ans = 0;
  for (auto it : mp)
  {
    int s = it.second.size();
    ans += (s * (s - 1)) / 2;
  }
  return ans;
}
int main()
{
  vector<int> arr = {3, 5, 1, 7, 8, 10, 62, 4, 6, 13};
  cout << f(arr);

  return 0;
}