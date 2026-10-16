// Striver A2Z DSA - Linked List Easy | Q4
// Problem: Insert a Node at the Head of Linked List
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Create new node, point its next to current head, return new head
// Time Complexity: O(1) | Space Complexity: O(1)

Node* insertAtHead(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    return newNode;
}

void printLL(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head = insertAtHead(head, 1);
    printLL(head); // 1 -> 2 -> 3 -> 4 -> NULL
    return 0;
}
