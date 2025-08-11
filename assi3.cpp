/*Implement a problem of smallest number with at least no trailing zeroes in factorial.   
Statement: Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes. */

#include <iostream>
using namespace std;

// Count trailing zeroes in x!
int countZero(int x) {
    int c = 0;
    while (x >= 5) {
        c += x / 5;
        x /= 5;
    }
    return c;
}

int findNum(int n) {
    int low = 0, high = n * 5, ans = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (countZero(mid) >= n) {
            ans = mid;
            high = mid - 1; // try smaller number
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Smallest number: " << findNum(n);
}
