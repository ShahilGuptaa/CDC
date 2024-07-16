// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // Write C++ code here
  vector<int> arr = {4, 3, 2, 3, 2, 3, 5, 4, 3};
  int cnt = 0;
  for (int i = 2; i < arr.size(); i++)
  {
    if (arr[i] != arr[0] && arr[i] != arr[1])
      cnt++;
  }
  cout << cnt;

  return 0;
}