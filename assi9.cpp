#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of children: ";
    cin >> n;
    
    int ratings[n];
    cout << "Enter ratings for each child: ";
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }
    
    int candies[n];
    
    // Initialize all children with 1 candy
    for (int i = 0; i < n; i++) {
        candies[i] = 1;
    }
    
    // Left to right pass: give more candies to children with higher rating than left neighbor
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i-1]) {
            candies[i] = candies[i-1] + 1;
        }
    }
    
    // Right to left pass: ensure children with higher rating than right neighbor get more candies
    for (int i = n-2; i >= 0; i--) {
        if (ratings[i] > ratings[i+1]) {
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
    
    // Calculate total candies
    int total = 0;
    for (int i = 0; i < n; i++) {
        total += candies[i];
    }
    
    cout << "Minimum candies needed: " << total << endl;
    
    return 0;
}