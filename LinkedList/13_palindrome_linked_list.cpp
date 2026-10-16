// Striver A2Z DSA - Linked List Easy | Q13
// Problem: Palindrome Linked List
// LeetCode: 234
// Link: https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Store values in vector, use two pointers to check palindrome
// Time Complexity: O(n) | Space Complexity: O(n)

bool isPalindrome(Node* head) {
    vector<int> vals;
    while (head) {
        vals.push_back(head->data);
        head = head->next;
    }
    int left = 0, right = vals.size() - 1;
    while (left < right) {
        if (vals[left++] != vals[right--]) return false;
    }
    return true;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome") << endl; // Palindrome
    return 0;
}
