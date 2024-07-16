// Online C++ compiler to run C++ program online
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int f(vector<int> arr, int right)
{
  sort(arr.begin(), arr.end());
  arr.push_back(right);
  int s = arr[0];
  int ans = arr[0];
  int n = arr.size();
  int j = 0;
  while (j < n)
  {
    ans += *lower_bound(arr.begin(), arr.end(), s + 10) - (s + 10);
    s = *lower_bound(arr.begin(), arr.end(), s + 10);
    j = lower_bound(arr.begin(), arr.end(), s + 10) - arr.begin();
  }
  return ans;
}

int main()
{
  // Write C++ code here
  vector<int> arr = {3, 7, 10, 15};
  cout << f(arr, 27);
  return 0;
}