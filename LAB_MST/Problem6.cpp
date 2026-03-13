#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = 0;

    for(int i = 0; i < 32; i++) {
        int count = 0;

        for(int j = 0; j < n; j++) {
            if(arr[j] & (1 << i)) {
                count++;
            }
        }

        if(count % 3 != 0) {
            result |= (1 << i);
        }
    }

    cout << result;
}