// Striver A2Z DSA - Strings Easy | Q1
// Problem: Remove Outermost Parentheses
// LeetCode: 1021
// Link: https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
using namespace std;

// Approach: Counter to track depth; skip when depth is 0 for '(' or 1 for ')'
// Time Complexity: O(n) | Space Complexity: O(n)

string removeOuterParentheses(string s) {
    string result = "";
    int balance = 0;
    for (char c : s) {
        if (c == '(' && balance++ > 0) result += c;
        if (c == ')' && --balance > 0) result += c;
    }
    return result;
}

int main() {
    cout << removeOuterParentheses("(()())(())") << endl;  // ()()()
    cout << removeOuterParentheses("((()))") << endl;       // ()
    return 0;
}
