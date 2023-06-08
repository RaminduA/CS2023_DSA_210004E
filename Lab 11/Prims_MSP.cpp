#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Define the graph as an adjacency list
typedef pair<int, int> Edge;  // (destination, weight)
typedef vector<vector<Edge>> Graph;

// Prim's algorithm to find the minimum spanning tree
vector<Edge> prim(const Graph& graph, int start) {
    vector<Edge> mst;  // Minimum Spanning Tree
    vector<bool> visited(graph.size(), false);
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;  // Priority queue to get the minimum-weight edge

    visited[start] = true;
    for (const auto& edge : graph[start]) {
        pq.push(edge);
    }

    while (!pq.empty()) {
        Edge minEdge = pq.top();
        pq.pop();
        int dest = minEdge.first;
        int weight = minEdge.second;

        if (visited[dest]) {
            continue;  // Skip if the destination node is already visited
        }

        visited[dest] = true;
        mst.push_back(minEdge);

        for (const auto& edge : graph[dest]) {
            if (!visited[edge.first]) {
                pq.push(edge);
            }
        }
    }

    return mst;
}

// Function to print the minimum spanning tree
void printMST(const vector<Edge>& mst) {
    int totalWeight = 0;
    for (const auto& edge : mst) {
        cout << edge.first << " -- " << edge.second << "\t" << edge.second << endl;
        totalWeight += edge.second;
    }
    cout << "Total weight: " << totalWeight << endl;
}

int main() {
    // Construct the graph
    Graph graph = {
        {{1, 3}, {5, 1}},  // Node 0
        {{0, 3}, {2, 2}, {3, 1}, {4, 10}},  // Node 1
        {{1, 2}, {3, 3}, {5, 5}},  // Node 2
        {{1, 1}, {2, 3}, {4, 5}},  // Node 3
        {{1, 10}, {3, 5}, {5, 4}},  // Node 4
        {{0, 1}, {2, 5}, {4, 4}}  // Node 5
    };

    int startNode = 0;

    // Find the minimum spanning tree using Prim's algorithm
    vector<Edge> minimumSpanningTree = prim(graph, startNode);

    // Print the minimum spanning tree
    cout << "Minimum Spanning Tree:" << endl;
    printMST(minimumSpanningTree);

    return 0;
}
