// Striver A2Z DSA - Arrays Easy | Q15
// Problem: Two Sum
// LeetCode: 1
// Link: https://leetcode.com/problems/two-sum/

#include <bits/stdc++.h>
using namespace std;

// Approach: HashMap - store seen elements and check complement
// Time Complexity: O(n) | Space Complexity: O(n)

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        if (mp.count(complement))
            return {mp[complement], i};
        mp[nums[i]] = i;
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = twoSum(nums, 9);
    cout << "[" << res[0] << ", " << res[1] << "]" << endl; // [0, 1]
    return 0;
}
