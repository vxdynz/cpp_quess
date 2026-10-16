// Striver A2Z DSA - Arrays Easy | Q8
// Problem: Linear Search in an Array
// Platform: GFG
// Link: https://www.geeksforgeeks.org/problems/search-an-element-in-an-array-1587115621/1

#include <bits/stdc++.h>
using namespace std;

// Approach: Traverse array, compare each element with target
// Time Complexity: O(n) | Space Complexity: O(1)

int linearSearch(vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    vector<int> arr = {4, 2, 9, 7, 5, 1};
    cout << "Index: " << linearSearch(arr, 7) << endl; // 3
    cout << "Index: " << linearSearch(arr, 6) << endl; // -1
    return 0;
}
