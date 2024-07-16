#include <bits/stdc++.h>
using namespace std;

int n, k, degree[301], deleted[301], seen[301], distnce[301], diameter;
vector<int> G[301];

void getDist(int node, int dist)
{
	seen[node] = 1;
	for(auto i: G[node])	{
		if(not seen[i])	{
			if(not deleted[i])	{
				getDist(i, dist+1);
			}
		}
	}
	distnce[node] = dist;
}

int getDiameter()
{
	memset(distnce, -1, sizeof distnce);
	memset(seen, 0, sizeof seen);
	for(int i=0; i<n; i++)	{
		if(not deleted[i])	{
			getDist(i, 0);
			break;
		}
	}
	int mxd = -1, mxi;
	for(int i=0; i<n; i++)	{
		if(distnce[i] > mxd)	{
			mxd = distnce[i];
			mxi = i;
		}
	}
	// cout << mxi << endl;
	memset(distnce, -1, sizeof distnce);
	memset(seen, 0, sizeof seen);
	getDist(mxi, 0);
	return *(max_element(distnce, distnce+n));
}

int calculate(int node)
{
	// cout << "calc " << node << endl;
	memset(distnce, 0, sizeof distnce);
	memset(seen, 0, sizeof seen);
	getDist(node, 0);
	int ret = 0;
	for(int i=0; i<n; i++)	
		if(distnce[i] == diameter)
			ret++;
	return ret;
}



int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0, u, v; i<n-1; i++)	{
		cin >> u >> v;
		--u; --v;
		G[u].push_back(v);
		G[v].push_back(u);
		degree[u]++; degree[v]++;
	}
	memset(deleted, 0, sizeof deleted);
	pair<int, int> best(0, -1);
	memset(seen, 0, sizeof seen);
	diameter = getDiameter();
	// cout << "fuck " << endl;
	for(int removed = 1; removed <= k; removed++)	{
		for(int i=0; i<n; i++)	{
			if(not deleted[i])	{
				if(degree[i] == 1)	{
					int temp = calculate(i);
					if(temp > best.first)
						best = {temp, i};
				}
			}
		}
		deleted[best.second] = 1;
		for(auto i: G[best.second])
			if(not deleted[i])
				degree[i]--;
		best = {0, -1};
		memset(seen, 0, sizeof seen);
		diameter = getDiameter();
	}
	cout << diameter << endl;
}
