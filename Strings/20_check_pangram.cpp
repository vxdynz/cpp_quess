// Striver A2Z DSA - Strings Easy | Q20
// Problem: Check if a String is a Pangram
// LeetCode: 1832
// Link: https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include <bits/stdc++.h>
using namespace std;

// Approach: Boolean array of 26 letters; mark each seen letter
// Time Complexity: O(n) | Space Complexity: O(1)

bool checkIfPangram(string sentence) {
    bool seen[26] = {};
    for (char c : sentence) {
        if (c >= 'a' && c <= 'z')
            seen[c - 'a'] = true;
    }
    for (bool b : seen) if (!b) return false;
    return true;
}

int main() {
    cout << (checkIfPangram("thequickbrownfoxjumpsoverthelazydog") ? "True" : "False") << endl; // True
    cout << (checkIfPangram("leetcode") ? "True" : "False") << endl;                            // False
    return 0;
}
