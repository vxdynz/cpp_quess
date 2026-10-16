// Striver A2Z DSA - Arrays Easy | Q14
// Problem: Longest Subarray with Sum = K (Positive numbers)
// Platform: GFG
// Link: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

#include <bits/stdc++.h>
using namespace std;

// Approach: Sliding Window (works for positive numbers only)
// Time Complexity: O(n) | Space Complexity: O(1)

int longestSubarrayWithSumK(vector<int>& arr, int k) {
    int left = 0, right = 0, sum = 0, maxLen = 0;
    while (right < arr.size()) {
        sum += arr[right];
        while (sum > k && left <= right) sum -= arr[left++];
        if (sum == k) maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

int main() {
    vector<int> arr = {1, 2, 3, 1, 1, 1, 1};
    cout << "Max length: " << longestSubarrayWithSumK(arr, 3) << endl; // 3 (subarray: 1,1,1)
    return 0;
}
