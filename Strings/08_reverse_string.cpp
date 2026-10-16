// Striver A2Z DSA - Strings Easy | Q8
// Problem: Reverse a String
// LeetCode: 344
// Link: https://leetcode.com/problems/reverse-string/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers from both ends swapping characters
// Time Complexity: O(n) | Space Complexity: O(1)

void reverseString(vector<char>& s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
        swap(s[left++], s[right--]);
    }
}

int main() {
    vector<char> s1 = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s1);
    for (char c : s1) cout << c; cout << endl; // olleh
    return 0;
}
