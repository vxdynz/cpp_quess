// Striver A2Z DSA - Arrays Easy | Q9
// Problem: Union of Two Sorted Arrays
// Platform: GFG
// Link: https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers + skip duplicates
// Time Complexity: O(n + m) | Space Complexity: O(n + m)

vector<int> unionArrays(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> res;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
            i++;
        } else {
            if (res.empty() || res.back() != b[j]) res.push_back(b[j]);
            j++;
        }
    }
    while (i < a.size()) { if (res.empty() || res.back() != a[i]) res.push_back(a[i]); i++; }
    while (j < b.size()) { if (res.empty() || res.back() != b[j]) res.push_back(b[j]); j++; }
    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5}, b = {1, 2, 3, 6, 7};
    for (int x : unionArrays(a, b)) cout << x << " "; // 1 2 3 4 5 6 7
    cout << endl;
    return 0;
}
