// Striver A2Z DSA - Strings Easy | Q19
// Problem: Add Binary
// LeetCode: 67
// Link: https://leetcode.com/problems/add-binary/

#include <bits/stdc++.h>
using namespace std;

// Approach: Simulate binary addition from right to left with carry
// Time Complexity: O(max(n, m)) | Space Complexity: O(max(n, m))

string addBinary(string a, string b) {
    string result = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        result += (char)('0' + sum % 2);
        carry = sum / 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    cout << addBinary("11", "1") << endl;   // 100
    cout << addBinary("1010", "1011") << endl; // 10101
    return 0;
}
