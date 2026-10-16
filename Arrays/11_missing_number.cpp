// Striver A2Z DSA - Arrays Easy | Q11
// Problem: Find the Missing Number in an Array
// LeetCode: 268
// Link: https://leetcode.com/problems/missing-number/

#include <bits/stdc++.h>
using namespace std;

// Approach 1: Sum Formula  n*(n+1)/2 - sum of array
// Approach 2: XOR (handles overflow better)
// Time Complexity: O(n) | Space Complexity: O(1)

int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int total = n * (n + 1) / 2;
    int sum = 0;
    for (int x : nums) sum += x;
    return total - sum;
}

int main() {
    vector<int> nums = {3, 0, 1};
    cout << "Missing: " << missingNumber(nums) << endl; // 2
    vector<int> nums2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    cout << "Missing: " << missingNumber(nums2) << endl; // 8
    return 0;
}
