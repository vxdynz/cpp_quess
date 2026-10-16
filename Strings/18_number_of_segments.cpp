// Striver A2Z DSA - Strings Easy | Q18
// Problem: Number of Segments in a String
// LeetCode: 434
// Link: https://leetcode.com/problems/number-of-segments-in-a-string/

#include <bits/stdc++.h>
using namespace std;

// Approach: Count transitions from space (or start) to non-space character
// Time Complexity: O(n) | Space Complexity: O(1)

int countSegments(string s) {
    int count = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ' && (i == 0 || s[i - 1] == ' '))
            count++;
    }
    return count;
}

int main() {
    cout << countSegments("Hello, my name is John") << endl; // 5
    cout << countSegments("   ") << endl;  // 0
    cout << countSegments("love") << endl; // 1
    return 0;
}
