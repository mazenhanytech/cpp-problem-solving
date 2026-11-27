// Problem: Fibonacci Number (Top-Down Memoization & Bottom-Up Tabulation)
// Approach:
//   1. fibMemo: Top-down DP caching previously computed values in 'memo'.
//   2. fibTabu: Bottom-up DP building the table from base cases (0, 1) up to n.
// Time Complexity: O(n) for both approaches
// Space Complexity: O(n) for both approaches

#include <iostream>
#include <vector>
using namespace std;

long fibMemo(int n, vector<long>& memo) {
    if (n <= 1) {
        return n;
    }

    if (memo[n] != -1) {
        return memo[n]; // Already computed
    }

    memo[n] = fibMemo(n - 1, memo) + fibMemo(n - 2, memo);
    return memo[n];
}

long fibTabu(int n) {
    if (n <= 1) {
        return n;
    }

    vector<long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n = 5;

    vector<long> memo(n + 1, -1);
    cout << "Memoization Fibonacci of " << n << " = " << fibMemo(n, memo) << endl;
    cout << "Tabulation Fibonacci of " << n << " = " << fibTabu(n) << endl;

    return 0;
}
