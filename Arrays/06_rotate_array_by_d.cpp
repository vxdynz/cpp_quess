// Striver A2Z DSA - Arrays Easy | Q6
// Problem: Rotate Array by D Places (Left Rotation)
// LeetCode: 189
// Link: https://leetcode.com/problems/rotate-array/

#include <bits/stdc++.h>
using namespace std;

// Approach: Reversal Algorithm - O(n) time, O(1) space
void leftRotateByD(vector<int>& arr, int d) {
    int n = arr.size();
    d = d % n;
    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    leftRotateByD(arr, 3);
    for (int x : arr) cout << x << " "; // 4 5 6 7 1 2 3
    cout << endl;
    return 0;
}
