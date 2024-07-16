#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

struct suffix
{
    int index;
    int rank[2];
};

int xmp(struct suffix a, struct suffix b){
    return (a.rank[0] == b.rank[0]) ? 
    (a.rank[1] < b.rank[1] ? 1 : 0) : 
    (a.rank[0] < b.rank[0] ? 1 : 0);
} 
    
vector<int> build(string &t, int n)
{
    struct suffix x[n];
    for (int i = 0; i < n; i++)
    {
        x[i].index = i;
        x[i].rank[0] = t[i] - 'a';
        x[i].rank[1] = ((i + 1) < n) ? (t[i + 1] - 'a') : -1;
    }
    sort(x, x + n, xmp);
    int ind[n];
    for (int k = 4; k < 2 * n; k = k * 2)
    {
        int rank = 0;
        int prev = x[0].rank[0];
        x[0].rank[0] = rank;
        ind[x[0].index] = 0;

        for (int i = 1; i < n; i++)
        {
            if (x[i].rank[0] == prev and x[i].rank[1] == x[i - 1].rank[1])
            {
                prev = x[i].rank[0];
                x[i].rank[0] = rank;
            }
            else
            {
                prev = x[i].rank[0];
                x[i].rank[0] = ++rank;
            }
            ind[x[i].index] = i;
        }
        for (int i = 0; i < n; i++)
        {
            int next = x[i].index + k / 2;
            x[i].rank[1] = (next < n) ? x[ind[next]].rank[0] : -1;
        }
        sort(x, x + n, xmp);
    }
    
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(x[i].index);
    }
    return arr;
}
vector<int> xd(string &t, vector<int> &arr)
{
    int n = arr.size();
    vector<int> lcp(n, 0);
    vector<int> inv(n, 0);
    for (int i = 0; i < n; i++)
    {
        inv[arr[i]] = i;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (inv[i] == n - 1)
        {
            k = 0;
            continue;
        }
        int j = arr[inv[i] + 1];
        while (i + k < n and j + k < n and t[i + k] == t[j + k])
        {
            k++;
        }
        lcp[inv[i]] = k;
        if (k > 0)
        {
            k--;
        }
    }
    
    return lcp;
}
long substringCalculator(string s)
{
    int n = s.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> suffixx = build(s, n);
    vector<int> lcp = xd(s, suffixx);
    long res = n - suffixx[0];
    for (int i = 1; i < lcp.size(); i++)
    {
        res += (n - suffixx[i]) - lcp[i - 1];
    }
    res++;
    return (res - 1);
}
// Driver code
int main()
{
    string str;
    cin >> str;
    if (str.length() == 0)
    {
        cout << "0\n";
    }
    else
    {
        cout << substringCalculator(str) << '\n';
    }
    return 0;
}