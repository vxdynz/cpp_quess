// Striver A2Z DSA - Arrays Easy | Q12
// Problem: Maximum Consecutive Ones
// LeetCode: 485
// Link: https://leetcode.com/problems/max-consecutive-ones/

#include <bits/stdc++.h>
using namespace std;

// Approach: Linear scan - track current and max count of 1s
// Time Complexity: O(n) | Space Complexity: O(1)

int findMaxConsecutiveOnes(vector<int>& nums) {
    int maxCount = 0, count = 0;
    for (int x : nums) {
        if (x == 1) {
            count++;
            maxCount = max(maxCount, count);
        } else {
            count = 0;
        }
    }
    return maxCount;
}

int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << "Max consecutive ones: " << findMaxConsecutiveOnes(nums) << endl; // 3
    return 0;
}
