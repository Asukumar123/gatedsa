#include <iostream>
#include <vector>
#include <queue>
#include <functional> 
using namespace std;

#define INF 2147483647

class Edge {
public:
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

void dijkstra(int src, vector<vector<Edge>>& g) {
    int V = g.size();
    vector<int> dist(V, INF);
    dist[src] = 0;

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto e : g[u]) {
            if (dist[e.v] > dist[u] + e.wt) {
                dist[e.v] = dist[u] + e.wt;
                pq.push({dist[e.v], e.v});
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
    g[0].push_back(Edge(2, 1));
    g[1].push_back(Edge(2, 2));
    g[1].push_back(Edge(3, 5));
    g[2].push_back(Edge(3, 8));
    g[2].push_back(Edge(4, 10));
    g[3].push_back(Edge(5, 6));
    g[4].push_back(Edge(5, 3));

    dijkstra(0, g);

    return 0;
}
