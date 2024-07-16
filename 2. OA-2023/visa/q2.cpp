#include <bits/stdc++.h>
using namespace std;
// Forest-Visa

pair<int, int> getnextnonzero(vector<int> arr, int s)
{
  for (int i = s; i < arr.size(); i++)
  {
    if (arr[i] != 0)
    {
      int temp = arr[i];
      return {i, temp};
    }
  }
  return {-1, 0};
}
pair<int, int> getprevnonzero(vector<int> arr, int s)
{
  for (int i = s; i >= 0; i--)
  {
    if (arr[i] != 0)
    {
      int temp = arr[i];
      return {i, temp};
    }
  }
  return {-1, 0};
}
int main()
{
  // Write C++ code here
  vector<int> arr = {35, 0, 50, 0, 0, 5, 0, 15, 0, 0, 45};
  int ind = 4;
  int sum = 0;
  vector<int> ans;
  while (sum < 100)
  {
    sum += getnextnonzero(arr, ind).second;
    if (sum < 100)
    {
      ans.push_back(getnextnonzero(arr, ind).first);
      arr[getnextnonzero(arr, ind).first] = 0;
      sum += getprevnonzero(arr, ind).second;
      if (sum < 100)
      {
        ans.push_back(getprevnonzero(arr, ind).first);
        arr[getprevnonzero(arr, ind).first] = 0;
      }
      else
      {
        ans.push_back(getprevnonzero(arr, ind).first);
        arr[getprevnonzero(arr, ind).first] = 0;
        break;
      }
    }
    else
    {
      ans.push_back(getnextnonzero(arr, ind).first);
      arr[getnextnonzero(arr, ind).first] = 0;
      break;
    }
  }
  for (auto it : ans)
    cout << it << " ";
  cout << endl;
  return 0;
}