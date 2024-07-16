#include <bits/stdc++.h>
using namespace std;

int f(vector<int> arr, int thresh)
{
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] > thresh && arr[i + 1] > thresh && arr[i + 2] > thresh && i + 1 < arr.size() && i + 2 < arr.size())
      return i;
  }
  return -1;
}

int main()
{
  vector<int> arr = {0, 1, 4, 3, 2, 5};
  cout << f(arr, 1);
}