// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

bool checknextchar(char a, char b)
{
  if ((int)a + 1 == (int)b || a == 'z' && b == 'a')
    return true;
  return false;
}
bool f(string s, string t)
{
  for (int i = 0; i < s.length(); i++)
  {
    if (!checknextchar(s[i], t[i]))
      return false;
  }
  return true;
}

int main()
{
  // Write C++ code here
  string s = "abyz";
  string t = "bczb";
  cout << f(s, t);

  return 0;
}