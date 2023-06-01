#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <limits>

using namespace std;

#define INF std::numeric_limits<int>::max()

// Structure to represent an edge in the graph
struct Edge {
    int destination;  // Destination node index
    int weight;       // Weight of the edge

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Structure to represent a node in the graph
struct Node {
    int label;               // Label of the node
    list<Edge> neighbours;   // List of neighbours of the node
};

// Structure to represent a graph
struct Graph {
    int numNodes;     // Number of nodes in the graph
    Node* nodes;      // Array of nodes in the graph

    Graph(int n) : numNodes(n) {
        nodes = new Node[numNodes];
    }

    // Initialize labels of nodes
    void initializeNodes() {
        for (int i = 0; i < numNodes; i++) {
            nodes[i].label = i;
        }
    }

    // Add an edge between two nodes in the graph
    void addEdge(int u, int v, int w) {
        nodes[u].neighbours.push_back(Edge(v, w));
        nodes[v].neighbours.push_back(Edge(u, w));
    }
};

// Dijkstra's algorithm to find the shortest paths from a source node to all other nodes
vector<int> dijkstra(Graph graph, int source) {
    int numCities = graph.numNodes;
    vector<int> distances(numCities, INF);   // Initialize all distances to infinity
    distances[source] = 0;                    // Make distance from source to itself is 0

    // Priority queue to store vertices with their distances
    // The pair contains: (distance, vertex)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});                     // Push the source node with distance 0

    while (!pq.empty()) {
        int u = pq.top().second;               // Get the vertex with minimum distance
        int distU = pq.top().first;            // Get the distance of u
        pq.pop();

        if (distU > distances[u])
            continue;                          // Skip if a shorter path to u has already been found

        // Iterate through the neighbours of u
        for (Edge edge : graph.nodes[u].neighbours) {
            int v = edge.destination;          // Get the neighbour
            int weight = edge.weight;          // Get the weight of the edge

            if (distU + weight < distances[v]) {
                distances[v] = distU + weight;  // Update the distance to v
                pq.push({distances[v], v});     // Add v to the priority queue with the new distance
            }
        }
    }

    return distances;                         // Return the distances to all nodes from the source
}

int main() {
    int numNodes = 6;
    Graph graph = Graph(numNodes);
    graph.initializeNodes();

    // Add edges to the graph
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 15);
    graph.addEdge(0, 5, 5);
    graph.addEdge(1, 2, 10);
    graph.addEdge(1, 3, 30);
    graph.addEdge(2, 3, 12);
    graph.addEdge(2, 4, 5);
    graph.addEdge(3, 5, 20);

    for (int k = 0; k < numNodes; k++) {
        int source = k;

        vector<int> shortestTimes = dijkstra(graph, source);

        cout << "\nShortest times from city " << source << ":\n";
        for (int i = 0; i < shortestTimes.size(); ++i) {
            if (i == source)
                continue;

            if (shortestTimes[i] == INF)
                cout << "City " << i << ": Not reachable\n";
            else
                cout << "City " << i << ": " << shortestTimes[i] << " minutes\n";
        }
    }

    return 0;
}