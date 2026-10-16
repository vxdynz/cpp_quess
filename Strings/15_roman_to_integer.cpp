// Striver A2Z DSA - Strings Easy | Q15
// Problem: Roman to Integer
// LeetCode: 13
// Link: https://leetcode.com/problems/roman-to-integer/

#include <bits/stdc++.h>
using namespace std;

// Approach: If current < next, subtract it; otherwise add it
// Time Complexity: O(n) | Space Complexity: O(1)

int romanToInt(string s) {
    unordered_map<char, int> val = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int total = 0;
    for (int i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && val[s[i]] < val[s[i + 1]])
            total -= val[s[i]];
        else
            total += val[s[i]];
    }
    return total;
}

int main() {
    cout << romanToInt("III") << endl;    // 3
    cout << romanToInt("LVIII") << endl;  // 58
    cout << romanToInt("MCMXCIV") << endl; // 1994
    return 0;
}
