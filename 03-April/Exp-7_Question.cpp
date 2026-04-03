#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<list<pair<int, int>>> graph(n);

    for (auto &f : flights) {
        int u = f[0];
        int v = f[1];
        int price = f[2];
        graph[u].push_back({v, price});
    }

    vector<int> dist(n, INT_MAX);
    queue<pair<int, int>> q;

    q.push({src, 0});
    dist[src] = 0;

    int stops = 0;

    while (!q.empty() && stops <= k) {
        int size = q.size();

        vector<int> temp = dist;

        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();

            int node = front.first;
            int cost = front.second;

            for (auto &p : graph[node]) {
                int neighbour = p.first;
                int price = p.second;

                if (temp[neighbour] > cost + price) {
                    temp[neighbour] = cost + price;
                    q.push({neighbour, temp[neighbour]});
                }
            }
        }

        dist = temp;
        stops++;
    }

    return (dist[dst] == INT_MAX) ? -1 : dist[dst];
}

int main() {
    int n, m;
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter number of flights: ";
    cin >> m;

    vector<vector<int>> flights(m, vector<int>(3));

    cout << "Enter flights (src dest price):\n";
    for (int i = 0; i < m; i++) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int src, dst, k;
    cout << "Enter source, destination and max stops: ";
    cin >> src >> dst >> k;

    int ans = findCheapestPrice(n, flights, src, dst, k);

    if (ans == -1)
        cout << "No valid route found\n";
    else
        cout << "Cheapest price: " << ans << endl;

    return 0;
}