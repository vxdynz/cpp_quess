// Striver A2Z DSA - Strings Easy | Q14
// Problem: Count and Say
// LeetCode: 38
// Link: https://leetcode.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std;

// Approach: Iteratively build the sequence using run-length encoding
// Time Complexity: O(n * m) where m is length of string | Space: O(m)

string countAndSay(int n) {
    string result = "1";
    for (int i = 1; i < n; i++) {
        string next = "";
        int j = 0;
        while (j < result.size()) {
            char digit = result[j];
            int count = 0;
            while (j < result.size() && result[j] == digit) {
                j++; count++;
            }
            next += to_string(count) + digit;
        }
        result = next;
    }
    return result;
}

int main() {
    cout << countAndSay(1) << endl; // 1
    cout << countAndSay(4) << endl; // 1211
    cout << countAndSay(5) << endl; // 111221
    return 0;
}
