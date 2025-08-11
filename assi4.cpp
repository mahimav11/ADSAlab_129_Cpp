#include <iostream>
using namespace std;

void merge(int a[], int l, int m, int r) {
    int temp[100], k = 0;
    int i = l, j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] < a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= m) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];

    for (int x = 0; x < k; x++)
        a[l + x] = temp[x];
}

void msort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    msort(a, l, m);
    msort(a, m + 1, r);
    merge(a, l, m, r);
}

int main() {
    int n, a[100];
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    msort(a, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
