#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0, ans = 0;

        while (r < n) {
            while (sum < 0 && l < r) {
                sum -= nums[l];
                l++;
            }

            sum += nums[r];
            r++;

            ans = max(sum, ans);
        }
        return ans;
    }

public:
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> a = nums, b = nums;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            a[i] = -a[i]; 
        }

        int max1 = maxSum(a);  // max subarray sum in original
        int max2 = maxSum(b);  // max subarray sum in inverted array

        return max(max1, max2);
    }
};

// Main function to test the solution
int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxAbsoluteSum(nums);
    cout << "Maximum absolute subarray sum: " << result << endl;

    return 0;
}
