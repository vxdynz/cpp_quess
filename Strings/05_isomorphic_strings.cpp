// Striver A2Z DSA - Strings Easy | Q5
// Problem: Isomorphic Strings
// LeetCode: 205
// Link: https://leetcode.com/problems/isomorphic-strings/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two maps for bijective character mapping
// Time Complexity: O(n) | Space Complexity: O(1) - fixed alphabet

bool isIsomorphic(string s, string t) {
    int mapST[256] = {}, mapTS[256] = {};
    for (int i = 0; i < s.size(); i++) {
        if (mapST[s[i]] != mapTS[t[i]]) return false;
        mapST[s[i]] = mapTS[t[i]] = i + 1;
    }
    return true;
}

int main() {
    cout << (isIsomorphic("egg", "add") ? "True" : "False") << endl;    // True
    cout << (isIsomorphic("foo", "bar") ? "True" : "False") << endl;    // False
    cout << (isIsomorphic("paper", "title") ? "True" : "False") << endl; // True
    return 0;
}
