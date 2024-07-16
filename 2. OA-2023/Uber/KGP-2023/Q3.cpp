#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> towers(n);
    int totalRings = 0;

    for (int i = 0; i < n; i++) {
        cin >> towers[i];
        totalRings += towers[i];
    }

    if (totalRings == b) {
        cout << "0\n";
        return 0;
    }

    int steps = 0;
    while (totalRings > n) {
        int maxRingsIndex = max_element(towers.begin(), towers.end()) - towers.begin();
        int adjacentTowerIndex;

        // Determine which adjacent tower has fewer rings
        if (maxRingsIndex == 0) {
            adjacentTowerIndex = 1;
        } else if (maxRingsIndex == n - 1) {
            adjacentTowerIndex = n - 2;
        } else {
            int leftAdjacentRings = towers[maxRingsIndex - 1];
            int rightAdjacentRings = towers[maxRingsIndex + 1];
            adjacentTowerIndex = leftAdjacentRings <= rightAdjacentRings ? maxRingsIndex - 1 : maxRingsIndex + 1;
        }

        int movedRings = min(towers[maxRingsIndex] - 1, totalRings - b);
        towers[maxRingsIndex] -= movedRings;
        towers[adjacentTowerIndex] += movedRings;
        totalRings -= movedRings;

        steps++;
    }

    cout << steps << "\n";

    return 0;
}