// Striver A2Z DSA - Strings Easy | Q6
// Problem: Check if One String is a Rotation of Another
// LeetCode: 796
// Link: https://leetcode.com/problems/rotate-string/

#include <bits/stdc++.h>
using namespace std;

// Approach: If s+s contains goal as a substring, it is a valid rotation
// Time Complexity: O(n) | Space Complexity: O(n)

bool rotateString(string s, string goal) {
    if (s.size() != goal.size()) return false;
    return (s + s).find(goal) != string::npos;
}

int main() {
    cout << (rotateString("abcde", "cdeab") ? "True" : "False") << endl; // True
    cout << (rotateString("abcde", "abced") ? "True" : "False") << endl; // False
    return 0;
}
