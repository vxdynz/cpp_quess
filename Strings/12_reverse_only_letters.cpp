// Striver A2Z DSA - Strings Easy | Q12
// Problem: Reverse Only Letters
// LeetCode: 917
// Link: https://leetcode.com/problems/reverse-only-letters/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers, swap only when both are letters
// Time Complexity: O(n) | Space Complexity: O(1)

string reverseOnlyLetters(string s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        while (left < right && !isalpha(s[left])) left++;
        while (left < right && !isalpha(s[right])) right--;
        swap(s[left++], s[right--]);
    }
    return s;
}

int main() {
    cout << reverseOnlyLetters("ab-cd") << endl;       // dc-ba
    cout << reverseOnlyLetters("a-bC-dEf-ghIj") << endl; // j-Ih-gfE-dCba
    return 0;
}
