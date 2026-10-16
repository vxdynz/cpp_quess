// Striver A2Z DSA - Arrays Easy | Q1
// Problem: Largest Element in an Array
// Platform: GFG
// Link: https://www.geeksforgeeks.org/problems/largest-element-in-array2531/1

#include <bits/stdc++.h>
using namespace std;

// Approach: Linear scan tracking the maximum element
// Time Complexity: O(n) | Space Complexity: O(1)

int largestElement(vector<int>& arr) {
    int maxElem = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > maxElem)
            maxElem = arr[i];
    }
    return maxElem;
}

int main() {
    vector<int> arr = {3, 1, 9, 5, 7, 2};
    cout << "Largest Element: " << largestElement(arr) << endl; // Output: 9
    return 0;
}
