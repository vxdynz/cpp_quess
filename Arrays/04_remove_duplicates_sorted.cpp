// Striver A2Z DSA - Arrays Easy | Q4
// Problem: Remove Duplicates from Sorted Array
// LeetCode: 26
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers
// Time Complexity: O(n) | Space Complexity: O(1)

int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}

int main() {
    vector<int> nums = {1, 1, 2, 3, 3, 4, 5, 5};
    int k = removeDuplicates(nums);
    cout << "Unique count: " << k << endl; // 5
    for (int i = 0; i < k; i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
