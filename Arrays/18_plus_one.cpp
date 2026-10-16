// Striver A2Z DSA - Arrays Easy | Q18
// Problem: Plus One
// LeetCode: 66
// Link: https://leetcode.com/problems/plus-one/

#include <bits/stdc++.h>
using namespace std;

// Approach: Traverse from end, handle carry propagation
// Time Complexity: O(n) | Space Complexity: O(1)

vector<int> plusOne(vector<int>& digits) {
    for (int i = digits.size() - 1; i >= 0; i--) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        }
        digits[i] = 0;
    }
    digits.insert(digits.begin(), 1); // overflow case e.g., 999 -> 1000
    return digits;
}

int main() {
    vector<int> d1 = {1, 2, 3};
    for (int x : plusOne(d1)) cout << x; cout << endl; // 124
    vector<int> d2 = {9, 9, 9};
    for (int x : plusOne(d2)) cout << x; cout << endl; // 1000
    return 0;
}
