// Striver A2Z DSA - Arrays Easy | Q2
// Problem: Second Largest Element in an Array
// Platform: GFG
// Link: https://www.geeksforgeeks.org/problems/second-largest0156/1

#include <bits/stdc++.h>
using namespace std;

// Approach: Single pass - track largest and second largest
// Time Complexity: O(n) | Space Complexity: O(1)

int secondLargest(vector<int>& arr) {
    int largest = INT_MIN, secondLar = INT_MIN;
    for (int x : arr) {
        if (x > largest) {
            secondLar = largest;
            largest = x;
        } else if (x > secondLar && x != largest) {
            secondLar = x;
        }
    }
    return secondLar;
}

int main() {
    vector<int> arr = {12, 35, 1, 10, 34, 1};
    cout << "Second Largest: " << secondLargest(arr) << endl; // Output: 34
    return 0;
}
