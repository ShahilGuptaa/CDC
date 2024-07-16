// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

bool istrue(string s, int k)
{
  int n = s.size();
  int i = 0;
  int j = 1, cnt = 1;
  while (j < n)
  {
    if (s[j - 1] == s[j])
    {
      cnt++;
      if (cnt == k)
      {
        if ((s[i - 1] && s[j + 1] && s[i - 1] != s[i] && s[j + 1] != s[j]) || (!s[j + 1] && s[i - 1] && s[i - 1] != s[i]) || (!s[i - 1] && s[j + 1] && s[j + 1] != s[j]))
          return true;
      }
      j++;
    }
    else
    {
      i = j;
      cnt = 1;
      j++;
    }
  }
  return false;
}

int check(vector<string> words, int k)
{
  int cnt = 0;
  for (auto it : words)
  {
    if (istrue(it, k))
      cnt++;
  }
  return cnt;
}

int main()
{
  // Write C++ code here
  int n; cin>>n;
  vector<string> words(n);
  for(int i=0;i<n;i++) cin>>words[i];
  int k = 1;
  // vector<string>words={"abc","abaaaccct","abaaaa","aaaaba"};
  // int k=3;
  cout << check(words, k);

  return 0;
}