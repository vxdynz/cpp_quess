// Striver A2Z DSA - Linked List Easy | Q10
// Problem: Detect a Cycle in Linked List
// LeetCode: 141
// Link: https://leetcode.com/problems/linked-list-cycle/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Floyds Cycle Detection - slow moves 1 step, fast 2 steps
// If they meet, there is a cycle
// Time Complexity: O(n) | Space Complexity: O(1)

bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(-4);
    // Create cycle: -4 -> 2
    head->next->next->next->next = head->next;
    cout << (hasCycle(head) ? "Cycle detected" : "No cycle") << endl; // Cycle detected
    return 0;
}
