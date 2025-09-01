/*Implement a problem of activity selection problem with K persons. 
Statement: Given two arrays S[] and E[] of size N denoting starting and closing time of the shops and an integer value K denoting the number of people, the task is to find out the maximum number of shops they can visit in total if they visit each shop optimally based on the following conditions: 
1. A shop can be visited by only one person. 
2. A person cannot visit another shop if its timing collides with it.*/


#include <iostream>
using namespace std;

struct Shop {
    int start, end;
};

// Sort shops by end time
void sortShops(Shop shops[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (shops[i].end > shops[j].end) {
                Shop temp = shops[i];
                shops[i] = shops[j];
                shops[j] = temp;
            }
        }
    }
}

int maxShopsVisited(int S[], int E[], int n, int K) {
    Shop shops[100]; // assuming max 100 shops
    for (int i = 0; i < n; i++) {
        shops[i].start = S[i];
        shops[i].end = E[i];
    }

    // Sort by end time
    sortShops(shops, n);

    int endTime[10]; // assuming max 10 persons
    for (int i = 0; i < K; i++) endTime[i] = -1;

    int count = 0;

    for (int i = 0; i < n; i++) {
        bool assigned = false;

        // check if any person is free
        for (int j = 0; j < K; j++) {
            if (endTime[j] <= shops[i].start) {
                endTime[j] = shops[i].end; // assign shop to this person
                count++;
                assigned = true;
                break;
            }
        }
        // if not assigned, skip this shop
    }

    return count;
}

int main() {
    int n, K;
    cout << "Enter number of shops: ";
    cin >> n;

    int S[100], E[100];
    cout << "Enter start times:\n";
    for (int i = 0; i < n; i++) cin >> S[i];
    cout << "Enter end times:\n";
    for (int i = 0; i < n; i++) cin >> E[i];

    cout << "Enter number of persons: ";
    cin >> K;

    int result = maxShopsVisited(S, E, n, K);
    cout << "Maximum shops visited: " << result << endl;

    return 0;
}
