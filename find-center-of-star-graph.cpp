// Problem: Find Center of Star Graph
// Approach: In a star graph, the center node is connected to every other node,
// so it must appear in the first two edges. Time: O(1), Space: O(1).

#include <iostream>
#include <vector>
using namespace std;

int findCenter(vector<vector<int>>& edges) {
    if (edges.size() < 2) return -1;

    int a = edges[0][0];
    int b = edges[0][1];
    int c = edges[1][0];
    int d = edges[1][1];

    // If 'a' appears in the second edge, 'a' is the center; otherwise 'b' is.
    if (a == c || a == d) {
        return a;
    }
    return b;
}

int main() {
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 2}};
    cout << findCenter(edges) << "\n";
    return 0;
}
