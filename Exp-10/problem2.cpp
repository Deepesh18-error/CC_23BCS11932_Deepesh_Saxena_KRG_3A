// Experiment - 2
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> mp;
        int overlap = 0, curMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                overlap++;
                continue;
            }

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            string key = to_string(dx) + "_" + to_string(dy);
            mp[key]++;
            curMax = max(curMax, mp[key]);
        }

        result = max(result, curMax + overlap + 1);
    }
    return result;
}// Experiment - 2
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if (n <= 2) return n;
    int result = 0;

    for (int i = 0; i < n; i++) {
        unordered_map<string, int> mp;
        int overlap = 0, curMax = 0;

        for (int j = i + 1; j < n; j++) {
            int dx = points[j][0] - points[i][0];
            int dy = points[j][1] - points[i][1];

            if (dx == 0 && dy == 0) {
                overlap++;
                continue;
            }

            int g = __gcd(dx, dy);
            dx /= g;
            dy /= g;

            string key = to_string(dx) + "_" + to_string(dy);
            mp[key]++;
            curMax = max(curMax, mp[key]);
        }

        result = max(result, curMax + overlap + 1);
    }
    return result;
}