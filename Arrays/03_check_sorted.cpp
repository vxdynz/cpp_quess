// Striver A2Z DSA - Arrays Easy | Q3
// Problem: Check if Array is Sorted and Rotated
// LeetCode: 1752
// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <bits/stdc++.h>
using namespace std;

// Approach: Count drops; sorted+rotated array has at most 1 drop
// Time Complexity: O(n) | Space Complexity: O(1)

bool check(vector<int>& nums) {
    int n = nums.size(), count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] > nums[(i + 1) % n])
            count++;
        if (count > 1) return false;
    }
    return true;
}

int main() {
    vector<int> arr1 = {3, 4, 5, 1, 2};
    vector<int> arr2 = {2, 1, 3, 4};
    cout << (check(arr1) ? "Yes" : "No") << endl; // Yes
    cout << (check(arr2) ? "Yes" : "No") << endl; // No
    return 0;
}
