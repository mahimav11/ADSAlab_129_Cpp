#include <iostream>
using namespace std;

int main() {
    int coins[] = {1, 2, 5, 10, 20};
    int N = 5;
    int sum = 70;

    long long dp[71];  // dp[i] = ways to make sum i
    for (int i = 0; i <= sum; i++)
        dp[i] = 0;

    dp[0] = 1;  // base case: 1 way to make sum 0

    for (int i = 0; i < N; i++) {
        int coin = coins[i];
        for (int j = coin; j <= sum; j++) {
            dp[j] += dp[j - coin];
        }
    }

    cout << "Number of ways = " << dp[sum] << endl;

    return 0;
}
