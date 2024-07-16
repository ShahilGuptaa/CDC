// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int f(vector<int> arr, int k)
{
  int n = arr.size();
  int i = 0, j = 0;
  int cnt = 0;
  int prev = -1, curr, len;
  while (j < n - 1 + k)
  {
    curr = arr[j % n];
    if (prev == curr)
    {
      i = j;
    }
    len = j - i + 1;
    prev = curr;
    if (len == k)
    {
      cnt++;
      len--;
      i++;
    }
    j++;
  }
  return cnt;
}
int main()
{
  // Write C++ code here
  // vector<int>arr={0,0,1,1,0,0,1,0,1};
  // int k=3;
  // vector<int>arr={0,1,0,1,1};
  // int k=4;
  vector<int> arr = {0, 1, 0, 1};
  int k = 4;
  cout << f(arr, k);

  return 0;
}