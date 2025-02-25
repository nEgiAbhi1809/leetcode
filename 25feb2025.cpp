#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1'000'000'007;
        long long oddCount = 0, evenCount = 1, prefixSum = 0, result = 0;

        for (int a : arr) {
            prefixSum += a;

            if (prefixSum % 2 == 0) {  
                result = (result + oddCount) % MOD;
                evenCount++;
            } else {  
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }

        return result;
    }
};

int main() {
    // Example Input
    vector<int> arr = {1, 3, 5};  // Example test case

    // Create an instance of the Solution class
    Solution sol;

    // Call the function and print the output
    cout << "Number of subarrays with odd sum: " << sol.numOfSubarrays(arr) << endl;

    return 0;
}
