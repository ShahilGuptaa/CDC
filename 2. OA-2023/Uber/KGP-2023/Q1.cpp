#include<bits/stdc++.h>
using namespace std;

using lli = long long int;
using ii = pair<lli, lli>;
const lli INF = 1e18;
#define F first
#define S second
const lli N = 200010;
const lli mod = 1000000007;

long long solve(int n, vector<int> arr)
{
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > 0)
                {
                    ans += (j - i);
                    if (j - 1 != i)
                    {
                        if (j - 1 >= 0 && arr[j] > 1)
                        {
                            arr[j - 1] += arr[j] - 1;
                            arr[j] = 1;
                        }
                        else
                        {
                            arr[i] = 1;
                            arr[j]-=1;
                        }
                    }
                    else
                    {
                        arr[j] -= 1;
                    }
                    break;
                }
            }
        }
        else if (arr[i] > 1)
        {
            ans += (arr[i] - 1);
            if (i + 1 < n) // Change the condition here
            {
                arr[i + 1] += 1;
                arr[i] = 1;
            }
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(n, arr) << '\n';
    }
}
