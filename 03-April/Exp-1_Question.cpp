#include <bits/stdc++.h>
using namespace std;

int triangularSum(vector<int>& nums) {
    int n = nums.size();
    
    long long coeff = 1;  
    long long result = 0;

    for (int i = 0; i < n; i++) {
        result = (result + nums[i] * coeff) % 10;
        
        coeff = coeff * (n - 1 - i) / (i + 1);
    }

    return result % 10;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int ans = triangularSum(nums);
    cout << "Triangular Sum = " << ans << endl;

    return 0;
}