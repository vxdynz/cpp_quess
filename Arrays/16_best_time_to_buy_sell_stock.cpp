// Striver A2Z DSA - Arrays Easy | Q16
// Problem: Best Time to Buy and Sell Stock
// LeetCode: 121
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <bits/stdc++.h>
using namespace std;

// Approach: Track minimum price seen so far, compute max profit at each step
// Time Complexity: O(n) | Space Complexity: O(1)

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << maxProfit(prices) << endl; // 5
    vector<int> prices2 = {7, 6, 4, 3, 1};
    cout << "Max Profit: " << maxProfit(prices2) << endl; // 0
    return 0;
}
