// Striver A2Z DSA - Linked List Easy | Q18
// Problem: Merge Two Sorted Linked Lists
// LeetCode: 21
// Link: https://leetcode.com/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Compare heads of both lists, pick smaller, advance that pointer
// Time Complexity: O(n + m) | Space Complexity: O(1)

Node* mergeSortedLists(Node* l1, Node* l2) {
    Node dummy(0);
    Node* curr = &dummy;
    while (l1 && l2) {
        if (l1->data <= l2->data) { curr->next = l1; l1 = l1->next; }
        else { curr->next = l2; l2 = l2->next; }
        curr = curr->next;
    }
    curr->next = l1 ? l1 : l2;
    return dummy.next;
}

void printLL(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* l1 = new Node(1); l1->next = new Node(3); l1->next->next = new Node(5);
    Node* l2 = new Node(2); l2->next = new Node(4); l2->next->next = new Node(6);
    Node* merged = mergeSortedLists(l1, l2);
    printLL(merged); // 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    return 0;
}
