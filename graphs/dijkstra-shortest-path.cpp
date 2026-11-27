// Topic: Dijkstra's Shortest Path Algorithm (Practice)
// Approach: Build an adjacency list (directed or undirected weighted graph) and use a min-heap
//           priority_queue storing {distance, node} to find shortest paths from a start node.
// Note: Assumes non-negative edge weights.
// Time Complexity: O((V + E) log V)
// Space Complexity: O(V + E)

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 1e9;

void addEdge(vector<vector<pair<int, int>>>& graph, int from, int to, int weight, bool isDirected) {
    graph[from].push_back({to, weight});
    if (!isDirected) {
        graph[to].push_back({from, weight});
    }
}

void dijkstra(const vector<vector<pair<int, int>>>& graph, int start, vector<int>& distance) {
    // Min-heap storing {current_shortest_distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node]) {
            continue;
        }

        for (const auto& neighbour : graph[node]) {
            int nextNode = neighbour.first;
            int weight = neighbour.second;

            if (dist + weight < distance[nextNode]) {
                distance[nextNode] = dist + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }
}

int main() {
    int nodes, edges;
    bool isDirected;

    cout << "Enter nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter 1 for directed and 0 for undirected: ";
    cin >> isDirected;

    vector<vector<pair<int, int>>> graph(nodes);

    for (int i = 0; i < edges; i++) {
        int from, to, weight;
        cout << "Enter from, to, and weight: ";
        cin >> from >> to >> weight;
        addEdge(graph, from, to, weight, isDirected);
    }

    vector<int> distance(nodes, INF);
    int start;

    cout << "Enter start node: ";
    cin >> start;

    dijkstra(graph, start, distance);

    cout << "Shortest distances from node " << start << ":" << endl;
    for (int i = 0; i < nodes; i++) {
        if (distance[i] == INF) {
            cout << "Node " << i << ": INF" << endl;
        } else {
            cout << "Node " << i << ": " << distance[i] << endl;
        }
    }

    return 0;
}
