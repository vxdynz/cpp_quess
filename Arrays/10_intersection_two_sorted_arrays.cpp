// Striver A2Z DSA - Arrays Easy | Q10
// Problem: Intersection of Two Sorted Arrays
// LeetCode: 349
// Link: https://leetcode.com/problems/intersection-of-two-arrays/

#include <bits/stdc++.h>
using namespace std;

// Approach: Two pointers
// Time Complexity: O(n + m) | Space Complexity: O(min(n, m))

vector<int> intersect(vector<int>& a, vector<int>& b) {
    int i = 0, j = 0;
    vector<int> res;
    while (i < a.size() && j < b.size()) {
        if (a[i] == b[j]) {
            if (res.empty() || res.back() != a[i]) res.push_back(a[i]);
            i++; j++;
        } else if (a[i] < b[j]) i++;
        else j++;
    }
    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5}, b = {2, 3, 5, 7};
    for (int x : intersect(a, b)) cout << x << " "; // 2 3 5
    cout << endl;
    return 0;
}
