#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Returns true if the val is a scam score, else false
bool isSolution(vector<int>& arr, int n, int k, int val) {
    int count = 0;
    for (int i : arr) {
        count += ceil(static_cast<double>(i) / val);
    }
    return count <= n;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> arr(k);
        for (int i = 0; i < k; i++) {
            cin >> arr[i];
        }

        int low = ceil(static_cast<double>(accumulate(arr.begin(), arr.end(), 0)) / n);
        int high = accumulate(arr.begin(), arr.end(), 0);
        int res = high;

        // Finds the minimum possible scam score
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isSolution(arr, n, k, mid)) {
                high = mid - 1;
                res = min(res, mid);
            } else {
                low = mid + 1;
            }
        }

        // Prints the res
        cout << res << endl;
    }

    return 0;
}
