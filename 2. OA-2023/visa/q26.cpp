// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
using namespace std;

string f(string s)
{
  int n = s.length();
  string temp = "";
  string minstring = s;
  for (int i = 0; i < n; i++)
  {
    temp += s[i];
    reverse(temp.begin(), temp.end());
    string temp2 = (i == n - 1) ? "" : s.substr(i + 1);
    string final = temp + temp2;
    // cout << final << endl;
    if (final < minstring)
    {
      minstring = final;
    }
    reverse(temp.begin(), temp.end());
  }
  cout << endl;
  temp = "";
  string minstring2 = s;
  for (int i = n - 1; i >= 0; i--)
  {
    temp += s[i];
    string temp2 = (i == 0) ? "" : s.substr(0, i);
    string final = temp2 + temp;
    // cout << final << endl;
    if (final < minstring2)
    {
      minstring2 = final;
    }
  }
  cout << endl;
  return min(minstring, minstring2);
}
int main()
{
  // Write C++ code here
  string s = "dbaca";
  cout << f(s);

  return 0;
}