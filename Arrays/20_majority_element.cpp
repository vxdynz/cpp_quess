// Striver A2Z DSA - Arrays Easy | Q20
// Problem: Majority Element (appears > n/2 times)
// LeetCode: 169
// Link: https://leetcode.com/problems/majority-element/

#include <bits/stdc++.h>
using namespace std;

// Approach: Boyers Moore Voting Algorithm
// candidate is maintained; count reflects net "votes"
// Time Complexity: O(n) | Space Complexity: O(1)

int majorityElement(vector<int>& nums) {
    int candidate = nums[0], count = 1;
    for (int i = 1; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
            count = 1;
        } else if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {3, 2, 3};
    cout << "Majority: " << majorityElement(nums) << endl; // 3
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority: " << majorityElement(nums2) << endl; // 2
    return 0;
}
