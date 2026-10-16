// Striver A2Z DSA - Linked List Easy | Q8
// Problem: Reverse a Linked List
// LeetCode: 206
// Link: https://leetcode.com/problems/reverse-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Iterative - keep prev and curr pointers
// Time Complexity: O(n) | Space Complexity: O(1)

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
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
    head = reverseList(head);
    printLL(head); // 4 -> 3 -> 2 -> 1 -> NULL
    return 0;
}
