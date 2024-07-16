// C++ program to finds out smallest range that includes
// elements from each of the given sorted lists.

#include <bits/stdc++.h>
using namespace std;

int ptr[501];
void findSmallestRange(vector<vector<int> >& arr, int N,int K)
{
	int i, minval, maxval, minrange, minel, maxel, flag,minind;
	for (i = 0; i <= K; i++)
		ptr[i] = 0;

	minrange = INT_MAX;

	while (1) {
		minind = -1;
		minval = INT_MAX;
		maxval = INT_MIN;
		flag = 0;

		for (i = 0; i < K; i++) {
			if (ptr[i] == N) {
				flag = 1;
				break;
			}
			if (ptr[i] < N && arr[i][ptr[i]] < minval) {
				minind = i; // update the index of the list
				minval = arr[i][ptr[i]];
			}
			if (ptr[i] < N && arr[i][ptr[i]] > maxval) {
				maxval = arr[i][ptr[i]];
			}
		}
		if (flag)
			break;

		ptr[minind]++;

		if ((maxval - minval) < minrange) {
			minel = minval;
			maxel = maxval;
			minrange = maxel - minel;
		}
	}

	printf("The smallest range is [%d, %d]\n", minel,maxel);
}
int main()
{
	vector<vector<int> > arr = { { 2, 4, 6, 8, 10 },
								{ 1, 3, 5, 7, 9 },
								{ 3, 4, 6, 8, 12 } };

	int K = arr.size();
	int N = arr[0].size();

	// Function call
	findSmallestRange(arr, N, K);

	return 0;
}
