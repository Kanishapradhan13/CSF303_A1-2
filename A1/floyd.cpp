
#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;

int main() {
    int V;
    cin >> V;

    vector<vector<long long>> dist(V, vector<long long>(V, INF));


    for (int i = 0; i < V; i++)
        dist[i][i] = 0;

    int E;
    cin >> E;
    for (int i = 0; i < E; i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }


    for (int mid = 0; mid < V; mid++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][mid] != INF && dist[mid][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);


    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative cycle detected\n";
            return 0;
        }
    }


    cout << "Distance matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }

    return 0;
}
