#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> mp;
        int same = 1, localMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                same++;
                continue;
            }

            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            string key = to_string(dx) + "/" + to_string(dy);
            mp[key]++;
            localMax = max(localMax, mp[key]);
        }

        result = max(result, localMax + same);
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    cout << maxPoints(points);
    return 0;
}