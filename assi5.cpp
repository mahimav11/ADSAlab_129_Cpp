#include <iostream>
using namespace std;

struct Building {
    int left, right, height;
};

int main() {
    int n;
    cout << "Enter number of buildings: ";
    cin >> n;

    Building b[50]; // limit for simplicity
    int edges[100][2]; // store (x, height), height negative for start
    int edgeCount = 0;

    cout << "Enter left, right, height for each building:\n";
    for (int i = 0; i < n; i++) {
        cin >> b[i].left >> b[i].right >> b[i].height;
        edges[edgeCount][0] = b[i].left;
        edges[edgeCount][1] = -b[i].height; // start
        edgeCount++;
        edges[edgeCount][0] = b[i].right;
        edges[edgeCount][1] = b[i].height; // end
        edgeCount++;
    }

    // Sort edges by x, then by height
    for (int i = 0; i < edgeCount - 1; i++) {
        for (int j = i + 1; j < edgeCount; j++) {
            if (edges[i][0] > edges[j][0] ||
               (edges[i][0] == edges[j][0] && edges[i][1] > edges[j][1])) {
                int tx = edges[i][0], th = edges[i][1];
                edges[i][0] = edges[j][0]; edges[i][1] = edges[j][1];
                edges[j][0] = tx; edges[j][1] = th;
            }
        }
    }

    int active[50]; // active building heights
    int activeCount = 0;
    int prevMax = 0;

    cout << "\nSkyline:\n";

    for (int e = 0; e < edgeCount; e++) {
        int x = edges[e][0];
        int h = edges[e][1];

        if (h < 0) { // start building
            active[activeCount++] = -h;
        } else { // end building
            for (int k = 0; k < activeCount; k++) {
                if (active[k] == h) {
                    active[k] = active[activeCount - 1];
                    activeCount--;
                    break;
                }
            }
        }

        // Find current max height
        int curMax = 0;
        for (int k = 0; k < activeCount; k++)
            if (active[k] > curMax) curMax = active[k];

        // If max height changes, print point
        if (curMax != prevMax) {
            cout << x << " " << curMax << "\n";
            prevMax = curMax;
        }
    }
}
