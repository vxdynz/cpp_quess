// Striver A2Z DSA - Strings Easy | Q4
// Problem: Longest Common Prefix
// LeetCode: 14
// Link: https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;

// Approach: Sort the array; compare only first and last strings
// Time Complexity: O(n*m log n) | Space Complexity: O(1)

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    sort(strs.begin(), strs.end());
    string first = strs.front(), last = strs.back();
    int i = 0;
    while (i < first.size() && first[i] == last[i]) i++;
    return first.substr(0, i);
}

int main() {
    vector<string> v1 = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(v1) << endl; // fl
    vector<string> v2 = {"dog", "racecar", "car"};
    cout << longestCommonPrefix(v2) << endl; // (empty)
    return 0;
}
