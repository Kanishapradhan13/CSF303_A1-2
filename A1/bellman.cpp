#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;

    vector<tuple<int,int,int>> edges(E);
    for (auto& [u, v, w] : edges)
        cin >> u >> v >> w;

    int src;
    cin >> src;

    vector<long long> dist(V, LLONG_MAX / 2);
    dist[src] = 0;

    for (int i = 0; i < V - 1; i++)
        for (auto& [u, v, w] : edges)
            if (dist[u] + w < dist[v])
                dist[v] = dist[u] + w;

    bool negative_cycle = false;
    for (auto& [u, v, w] : edges)
        if (dist[u] + w < dist[v])
            negative_cycle = true;

    if (negative_cycle) {
        cout << "Negative cycle detected\n";
    } else {
        for (int i = 0; i < V; i++)
            cout << "Vertex " << i << " : "
                 << (dist[i] >= LLONG_MAX / 2 ? -1 : dist[i]) << "\n";
    }

    return 0;
}