// Striver A2Z DSA - Strings Easy | Q17
// Problem: Longest Palindromic Substring
// LeetCode: 5
// Link: https://leetcode.com/problems/longest-palindromic-substring/

#include <bits/stdc++.h>
using namespace std;

// Approach: Expand around center for each index (odd & even length)
// Time Complexity: O(n^2) | Space Complexity: O(1)

string longestPalindrome(string s) {
    int start = 0, maxLen = 1;
    auto expand = [&](int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                maxLen = right - left + 1;
                start = left;
            }
            left--; right++;
        }
    };
    for (int i = 0; i < s.size(); i++) {
        expand(i, i);     // odd length
        expand(i, i + 1); // even length
    }
    return s.substr(start, maxLen);
}

int main() {
    cout << longestPalindrome("babad") << endl; // bab or aba
    cout << longestPalindrome("cbbd") << endl;  // bb
    return 0;
}
