#include <iostream>
using namespace std;

int maxProfit(int arr[], int n) {
    int profit = 0;

    // Traverse the array
    for (int i = 1; i < n; i++) {
        // If price is increasing, add profit
        if (arr[i] > arr[i - 1]) {
            profit += arr[i] - arr[i - 1];
        }
    }
    return profit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int arr[n];
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Maximum Profit: " << maxProfit(arr, n) << endl;
    return 0;
}