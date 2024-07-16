#include <bits/stdc++.h>
using namespace std;

string f(string s)
{
  int cntU = 0, cntD = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (s[i] == 'U')
      cntU++;
    else if (s[i] == 'D')
      cntD++;
  }
  int ans = cntU - cntD;
  if (ans > 0)
    return "U";
  if (ans < 0)
    return "D";
  return "T";
}

int main()
{
}
