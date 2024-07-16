// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  // Write C++ code here
  vector<int> arr = {3, 4, 5, 1, 0};
  int cntg = 0, cnts = 0;
  int pivot = 3;
  for (int i = 0; i < arr.size(); i++)
  {
    if (arr[i] > pivot)
      cntg++;
    if (arr[i] < pivot)
      cnts++;
  }
  if (cntg > cnts)
    cout << "GREATER" << endl;
  else if (cntg < cnts)
    cout << "SMALLER" << endl;
  else
    cout << "EQUAL" << endl;

  return 0;
}