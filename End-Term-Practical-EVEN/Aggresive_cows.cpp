#include <bits/stdc++.h>
using namespace std;

bool canPlace(vector<int>& a, int k, int dist) {
    int cows = 1;
    int last = a[0];

    for (int i = 1; i < a.size(); i++) {
        if (a[i] - last >= dist) {
            cows++;
            last = a[i];
        }
    }

    return cows >= k;
}

int aggressiveCows(vector<int>& a, int k) {
    sort(a.begin(), a.end());

    int low = 1;
    int high = a.back() - a[0];
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canPlace(a, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stalls(n);

    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    cout << aggressiveCows(stalls, k);

    return 0;
}