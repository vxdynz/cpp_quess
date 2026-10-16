// Striver A2Z DSA - Strings Easy | Q3
// Problem: Largest Odd Number in a String
// LeetCode: 1903
// Link: https://leetcode.com/problems/largest-odd-number-in-a-string/

#include <bits/stdc++.h>
using namespace std;

// Approach: Scan from right; first odd digit marks the longest odd prefix
// Time Complexity: O(n) | Space Complexity: O(1)

string largestOddNumber(string num) {
    for (int i = num.size() - 1; i >= 0; i--) {
        if ((num[i] - '0') % 2 != 0)
            return num.substr(0, i + 1);
    }
    return "";
}

int main() {
    cout << largestOddNumber("52") << endl;    // 5
    cout << largestOddNumber("4206") << endl;  // ""
    cout << largestOddNumber("35427") << endl; // 35427
    return 0;
}
