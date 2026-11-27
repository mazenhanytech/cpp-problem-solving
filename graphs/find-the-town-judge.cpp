// Problem: Find the Town Judge
// Approach: Track net trust score (in-degree minus out-degree) for each person from 1 to n.
//           The town judge must have a score of (n - 1): trusted by everyone else and trusts no one.
// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include <iostream>
#include <vector>
using namespace std;

int findJudge(int n, const vector<vector<int>>& trust) {
    vector<int> trustScore(n + 1, 0);

    for (const auto& t : trust) {
        int a = t[0]; // a trusts b
        int b = t[1]; // b is trusted by a

        trustScore[a]--; // trusts someone -> cannot be judge
        trustScore[b]++; // trusted by someone
    }

    for (int i = 1; i <= n; i++) {
        if (trustScore[i] == n - 1) {
            return i;
        }
    }

    return -1;
}

int main() {
    // Example 1 -> Output: 2
    int n1 = 2;
    vector<vector<int>> trust1 = {{1, 2}};
    cout << "Town Judge is: " << findJudge(n1, trust1) << endl;

    // Example 2 -> Output: 3
    int n2 = 3;
    vector<vector<int>> trust2 = {{1, 3}, {2, 3}};
    cout << "Town Judge is: " << findJudge(n2, trust2) << endl;

    // Example 3 -> Output: -1
    int n3 = 3;
    vector<vector<int>> trust3 = {{1, 3}, {2, 3}, {3, 1}};
    cout << "Town Judge is: " << findJudge(n3, trust3) << endl;

    return 0;
}
