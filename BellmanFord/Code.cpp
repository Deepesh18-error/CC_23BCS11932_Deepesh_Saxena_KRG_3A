#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int,int,int>> edges;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    int src;
    cin >> src;

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++) {
        for(auto e : edges) {
            int u, v, w;
            tie(u, v, w) = e;
            if(dist[u] != 1e9 && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
}