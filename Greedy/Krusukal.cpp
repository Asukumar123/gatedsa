#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
We will implement Kruskal's algorithm using:
1. Edge list representation of graph
2. Disjoint Set Union (Union-Find) data structure
*/

// Structure to represent an edge
struct Edge {
    int u, v, w; // u = source, v = destination, w = weight
};

// Disjoint Set Union (Union-Find) class
class DSU {
    vector<int> parent, rank;

public:
    // Constructor: initialize DSU with n vertices
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        // Initially, each vertex is its own parent (Make_Set operation)
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    // Find operation with path compression
    int findSet(int x) {
        if (parent[x] != x)
            parent[x] = findSet(parent[x]); // Path compression
        return parent[x];
    }

    // Union operation using rank
    void unionSet(int x, int y) {
        int px = findSet(x);
        int py = findSet(y);

        if (px != py) {
            // Attach smaller rank tree under larger rank tree
            if (rank[px] < rank[py])
                parent[px] = py;
            else if (rank[px] > rank[py])
                parent[py] = px;
            else {
                parent[py] = px;
                rank[px]++;
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<Edge> edges(E);

    cout << "Enter edges (u v w):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // Step 1: Sort all edges in non-decreasing order of weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.w < b.w;
    });

    // Step 2: Create DSU for V vertices (Make_Set for each vertex)
    DSU dsu(V);

    vector<Edge> mst; // To store edges of MST
    int totalWeight = 0;

    // Step 3: Process edges one by one
    for (Edge e : edges) {
        int u = e.u;
        int v = e.v;
        int w = e.w;

        // If u and v belong to different sets, include this edge
        if (dsu.findSet(u) != dsu.findSet(v)) {
            mst.push_back(e);        // Add edge to MST
            totalWeight += w;        // Add weight
            dsu.unionSet(u, v);      // Union their sets
        }
    }

    // Output MST
    cout << "\nEdges in Minimum Spanning Tree:\n";
    for (Edge e : mst) {
        cout << e.u << " - " << e.v << " : " << e.w << endl;
    }

    cout << "Total weight of MST = " << totalWeight << endl;

    return 0;
}
