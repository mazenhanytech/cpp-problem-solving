// Problem: Factorial (Top-Down Memoization & Bottom-Up Tabulation)
// Approach:
//   1. factorialMemo: Top-down DP caching previously computed factorials in 'memo'.
//   2. factorialTabu: Bottom-up DP iteratively computing factorials from 2 up to n.
// Note: Uses long long to handle larger factorials without quick overflow.
// Time Complexity: O(n) for both approaches
// Space Complexity: O(n) for both approaches

#include <iostream>
#include <vector>
using namespace std;

long long factorialMemo(int n, vector<long long>& memo) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (memo[n] != -1) {
        return memo[n]; // Already computed
    }

    memo[n] = n * factorialMemo(n - 1, memo);
    return memo[n];
}

long long factorialTabu(int n) {
    vector<long long> dp(n + 1, 1);

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] * i;
    }

    return dp[n];
}

int main() {
    int n = 5;

    vector<long long> memo(n + 1, -1);
    cout << "Memoization Factorial of " << n << " = " << factorialMemo(n, memo) << endl;
    cout << "Tabulation Factorial of " << n << " = " << factorialTabu(n) << endl;

    return 0;
}
