// Striver A2Z DSA - Arrays Easy | Q5
// Problem: Left Rotate an Array by One Place
// Platform: GFG / Custom

#include <bits/stdc++.h>
using namespace std;

// Approach: Store first element, shift left, place at end
// Time Complexity: O(n) | Space Complexity: O(1)

void leftRotateByOne(vector<int>& arr) {
    int n = arr.size();
    int temp = arr[0];
    for (int i = 1; i < n; i++)
        arr[i - 1] = arr[i];
    arr[n - 1] = temp;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    leftRotateByOne(arr);
    for (int x : arr) cout << x << " "; // 2 3 4 5 1
    cout << endl;
    return 0;
}
