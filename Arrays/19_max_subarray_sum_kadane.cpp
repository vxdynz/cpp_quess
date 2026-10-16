// Striver A2Z DSA - Arrays Easy | Q19
// Problem: Maximum Subarray Sum (Kadanes Algorithm)
// LeetCode: 53
// Link: https://leetcode.com/problems/maximum-subarray/

#include <bits/stdc++.h>
using namespace std;

// Approach: Kadane's Algorithm
// At each index, decide to extend previous subarray or start fresh
// Time Complexity: O(n) | Space Complexity: O(1)

int maxSubArray(vector<int>& nums) {
    int maxSum = nums[0], currentSum = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        currentSum = max(nums[i], currentSum + nums[i]);
        maxSum = max(maxSum, currentSum);
    }
    return maxSum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max subarray sum: " << maxSubArray(nums) << endl; // 6
    return 0;
}
