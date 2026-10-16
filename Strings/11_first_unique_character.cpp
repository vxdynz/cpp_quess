// Striver A2Z DSA - Strings Easy | Q11
// Problem: First Unique Character in a String
// LeetCode: 387
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/

#include <bits/stdc++.h>
using namespace std;

// Approach: Frequency array, then find first char with freq = 1
// Time Complexity: O(n) | Space Complexity: O(1)

int firstUniqChar(string s) {
    int freq[26] = {};
    for (char c : s) freq[c - 'a']++;
    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i] - 'a'] == 1) return i;
    }
    return -1;
}

int main() {
    cout << firstUniqChar("leetcode") << endl;  // 0 (l)
    cout << firstUniqChar("loveleetcode") << endl; // 2 (v)
    cout << firstUniqChar("aabb") << endl;      // -1
    return 0;
}
