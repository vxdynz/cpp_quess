// Striver A2Z DSA - Strings Easy | Q13
// Problem: String to Integer (atoi)
// LeetCode: 8
// Link: https://leetcode.com/problems/string-to-integer-atoi/

#include <bits/stdc++.h>
using namespace std;

// Approach: Simulate the atoi function step by step
// Time Complexity: O(n) | Space Complexity: O(1)

int myAtoi(string s) {
    int i = 0, sign = 1;
    long result = 0;
    // Skip whitespace
    while (i < s.size() && s[i] == ' ') i++;
    // Check sign
    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    // Read digits
    while (i < s.size() && isdigit(s[i])) {
        result = result * 10 + (s[i++] - '0');
        if (result * sign > INT_MAX) return INT_MAX;
        if (result * sign < INT_MIN) return INT_MIN;
    }
    return (int)(result * sign);
}

int main() {
    cout << myAtoi("42") << endl;         // 42
    cout << myAtoi("   -42") << endl;    // -42
    cout << myAtoi("4193 with words") << endl; // 4193
    return 0;
}
