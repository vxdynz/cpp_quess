// Striver A2Z DSA - Arrays Easy | Q13
// Problem: Find the Number that Appears Once (others appear twice)
// LeetCode: 136
// Link: https://leetcode.com/problems/single-number/

#include <bits/stdc++.h>
using namespace std;

// Approach: XOR - a^a = 0 and a^0 = a
// All pairs cancel out, leaving the single number
// Time Complexity: O(n) | Space Complexity: O(1)

int singleNumber(vector<int>& nums) {
    int result = 0;
    for (int x : nums) result ^= x;
    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number: " << singleNumber(nums) << endl; // 4
    vector<int> nums2 = {2, 2, 1};
    cout << "Single number: " << singleNumber(nums2) << endl; // 1
    return 0;
}
