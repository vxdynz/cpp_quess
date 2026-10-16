// Striver A2Z DSA - Strings Easy | Q16
// Problem: Excel Sheet Column Number
// LeetCode: 171
// Link: https://leetcode.com/problems/excel-sheet-column-number/

#include <bits/stdc++.h>
using namespace std;

// Approach: Treat as base-26 number system
// Time Complexity: O(n) | Space Complexity: O(1)

int titleToNumber(string columnTitle) {
    int result = 0;
    for (char c : columnTitle) {
        result = result * 26 + (c - 'A' + 1);
    }
    return result;
}

int main() {
    cout << titleToNumber("A") << endl;   // 1
    cout << titleToNumber("AB") << endl;  // 28
    cout << titleToNumber("ZY") << endl;  // 701
    return 0;
}
