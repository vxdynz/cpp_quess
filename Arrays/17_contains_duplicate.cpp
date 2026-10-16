// Striver A2Z DSA - Arrays Easy | Q17
// Problem: Contains Duplicate
// LeetCode: 217
// Link: https://leetcode.com/problems/contains-duplicate/

#include <bits/stdc++.h>
using namespace std;

// Approach: Use unordered_set - insert and check if already exists
// Time Complexity: O(n) | Space Complexity: O(n)

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    cout << (containsDuplicate(nums1) ? "True" : "False") << endl; // True
    vector<int> nums2 = {1, 2, 3, 4};
    cout << (containsDuplicate(nums2) ? "True" : "False") << endl; // False
    return 0;
}
