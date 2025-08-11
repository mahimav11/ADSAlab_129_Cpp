// Implement the problem of moving all zeroes to the end of array. 
// Statement: Given an array of random numbers, Push all the zeroes of a given array to the end of the array. 


#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int temp[100], k = 0;

    for (int i = l; i <= m; i++) // non-zero from left part
        if (a[i] != 0) temp[k++] = a[i];

    for (int i = m + 1; i <= r; i++) // non-zero from right part
        if (a[i] != 0) temp[k++] = a[i];

    while (k < (r - l + 1)) // fill rest with 0
        temp[k++] = 0;

    for (int i = 0; i < k; i++)
        a[l + i] = temp[i];
}

void moveZero(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    moveZero(a, l, m);
    moveZero(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n, a[100];
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    moveZero(a, 0, n - 1);

    cout << "After moving zeroes: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
