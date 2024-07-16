#include <iostream>
#include <string>
using namespace std;

int minCoinsForGrouping(string cells, int x, int y) {
    // Step 1: Identify consecutive groups of food cells
    int n = cells.length();
    int totalMoveCost = 0, totalCleanCost = 0;
    int i = 0;
    while (i < n) {
        if (cells[i] == 'F') {
            // Calculate the size of the current group
            int groupSize = 1;
            while (i + groupSize < n && cells[i + groupSize] == 'F') {
                groupSize++;
            }

            // Step 2: Calculate the cost of moving food cells to group them consecutively
            totalMoveCost += (groupSize - 1) * x;

            i += groupSize; // Move to the next cell after the current group
        } else {
            // Step 3: Calculate the cost of cleaning dirty cells
            if (cells[i] == 'D') {
                totalCleanCost += y;
            }
            i++; // Move to the next cell
        }
    }

    return totalMoveCost + totalCleanCost;
}

int main() {
    string cells = "---F-FD-F--";
    int queries[][2] = {{0, 10}, {10, 0}, {1, 1}};
    int numQueries = sizeof(queries) / sizeof(queries[0]);

    // Sample Output
    for (int i = 0; i < numQueries; i++) {
        int x = queries[i][0];
        int y = queries[i][1];
        cout << minCoinsForGrouping(cells, x, y) << " ";
    }
    cout << endl;

    return 0;
}
