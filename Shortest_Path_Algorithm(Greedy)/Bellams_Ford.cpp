#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

#define INT_MAX 2147483647

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void bellamFord(int src, vector<vector<Edge>>& g) {
    int V = g.size();
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++) {
        for (int u = 0; u < V; u++) {
            for (auto e : g[u]) {
                if (dist[e.v] > dist[u] + e.wt) {
                    dist[e.v] = dist[u] + e.wt;
                }
            }
        }
    }

    // Check for negative-weight cycles
    for (int u = 0; u < V; u++) {
        for (auto e : g[u]) {
            if (dist[e.v] > dist[u] + e.wt) {
                cout << "Graph contains negative weight cycle" << endl;
                return;
            }
        }
    }

    cout << "OUTPUT:\n";
    for (int i = 0; i < V; i++) {
        cout << "0 -> " << i << " = " << dist[i] << endl;
    }
}

int main() {
    int V = 6;
    vector<vector<Edge>> g(V);

    g[0].push_back(Edge(1, 4));
    g[0].push_back(Edge(-2, 1));
    g[1].push_back(Edge(2, 2));
    g[1].push_back(Edge(3, 5));
    g[2].push_back(Edge(3, 8));
    g[2].push_back(Edge(-4, 10));
    g[3].push_back(Edge(-5, 6));
    g[4].push_back(Edge(5, 3));

    bellamFord(0, g);

    return 0;
}
