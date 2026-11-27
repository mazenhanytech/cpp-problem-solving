// Problem: Minimum Score of a Path Between Two Cities
// Approach: Build an undirected weighted adjacency list and run DFS starting from node 1,
//           taking the minimum edge weight among all edges reachable from node 1.
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)

#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void dfs(int city, const vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int& ans) {
    visited[city] = true;

    for (const auto& neighbor : adj[city]) {
        int nextCity = neighbor.first;
        int distance = neighbor.second;

        ans = min(ans, distance);

        if (!visited[nextCity]) {
            dfs(nextCity, adj, visited, ans);
        }
    }
}

int minScore(int n, const vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> adj(n + 1);

    for (const auto& road : roads) {
        int a = road[0];
        int b = road[1];
        int dist = road[2];

        adj[a].push_back({b, dist});
        adj[b].push_back({a, dist});
    }

    vector<bool> visited(n + 1, false);
    int ans = INT_MAX;

    dfs(1, adj, visited, ans);

    return ans;
}

int main() {
    int n = 4;

    vector<vector<int>> roads = {
        {1, 2, 9},
        {2, 3, 6},
        {2, 4, 5},
        {1, 4, 7}
    };

    cout << "Minimum Score = " << minScore(n, roads) << endl;

    return 0;
}
