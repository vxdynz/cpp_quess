// Striver A2Z DSA - Linked List Easy | Q19
// Problem: Remove Nth Node from End of List
// LeetCode: 19
// Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Two pointers - fast moves n steps ahead, then both move together
// When fast reaches end, slow is at the node before target
// Time Complexity: O(n) | Space Complexity: O(1)

Node* removeNthFromEnd(Node* head, int n) {
    Node dummy(0);
    dummy.next = head;
    Node* fast = &dummy;
    Node* slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) { slow = slow->next; fast = fast->next; }
    Node* temp = slow->next;
    slow->next = temp->next;
    delete temp;
    return dummy.next;
}

void printLL(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head = removeNthFromEnd(head, 2);
    printLL(head); // 1 -> 2 -> 3 -> 5 -> NULL
    return 0;
}
