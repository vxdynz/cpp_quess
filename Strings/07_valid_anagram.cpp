// Striver A2Z DSA - Strings Easy | Q7
// Problem: Valid Anagram
// LeetCode: 242
// Link: https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std;

// Approach: Frequency count array of size 26
// Time Complexity: O(n) | Space Complexity: O(1)

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    int freq[26] = {};
    for (char c : s) freq[c - 'a']++;
    for (char c : t) freq[c - 'a']--;
    for (int x : freq) if (x != 0) return false;
    return true;
}

int main() {
    cout << (isAnagram("anagram", "nagaram") ? "True" : "False") << endl; // True
    cout << (isAnagram("rat", "car") ? "True" : "False") << endl;         // False
    return 0;
}
