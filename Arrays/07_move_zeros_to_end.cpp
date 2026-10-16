// Striver A2Z DSA - Arrays Easy | Q7
// Problem: Move Zeroes to End
// LeetCode: 283
// Link: https://leetcode.com/problems/move-zeroes/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers
// Time Complexity: O(n) | Space Complexity: O(1)

void moveZeroes(vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    for (int x : nums) cout << x << " "; // 1 3 12 0 0
    cout << endl;
    return 0;
}
