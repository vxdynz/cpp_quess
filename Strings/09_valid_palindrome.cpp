// Striver A2Z DSA - Strings Easy | Q9
// Problem: Valid Palindrome
// LeetCode: 125
// Link: https://leetcode.com/problems/valid-palindrome/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers; skip non-alphanumeric chars; compare case-insensitively
// Time Complexity: O(n) | Space Complexity: O(1)

bool isPalindrome(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++; right--;
    }
    return true;
}

int main() {
    cout << (isPalindrome("A man, a plan, a canal: Panama") ? "True" : "False") << endl; // True
    cout << (isPalindrome("race a car") ? "True" : "False") << endl;                     // False
    return 0;
}
