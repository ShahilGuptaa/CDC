#include <bits/stdc++.h>
#define int long long
const int mod = 1000000007;
using namespace std;

int parent[26];
int rk[26];
int indegree[26], outdegree[26];
// finding parent fxn

int find(int x)
{
    if (parent[x] == x)
        return x;
    else
        return parent[x] = find(parent[x]);
}

bool same(int x, int y)
{
    int a1 = find(x), a2 = find(y);
    return a1 == a2;
}

void unite(int x, int y)
{
    int xroot = find(x), yroot = find(y);
    if (xroot > yroot)
    {
        unite(y, x);
        return;
    }
    if (xroot == yroot)
        return;
    parent[xroot] = yroot;
    rk[yroot] += rk[xroot];
    return;
}

string solution(vector<string> &A)
{
    // Implement your solution here
    for (int i = 0; i < 26; i++)
    {
        rk[i] = 1;
        parent[i] = i;
        indegree[i] = 0;
        outdegree[i] = 0;
    }

    string ans = "";
    set<int> vis;
    for (auto i : A)
    {
        unite(i[0] - 'a', i[1] - 'a');
        outdegree[i[0] - 'a']++;
        indegree[i[1] - 'a']++;
        vis.insert(i[0] - 'a');
        vis.insert(i[1] - 'a');
        int flag = 1;
        int par = find(i[0] - 'a');
        int cnt = 0, cnt2 = 0;
        for (auto j : vis)
        {
            if (par != find(j))
                flag = 0;
            if (indegree[j] == outdegree[j]){
            }
            else if (indegree[j] == outdegree[j] + 1){
                cnt++;
            }
            else if (indegree[j] + 1 == outdegree[j]){
                cnt2++;
            }
            else{
                flag = 0;
            }
        }
        if (cnt > 1 || cnt2 > 1){
            flag = 0;
        }
        ans += (flag + '0');
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<string> A;

        while (n--)
        {
            string a;
            cin >> a;
            A.push_back(a);
        }
        cout << solution(A) << endl;
    }
}