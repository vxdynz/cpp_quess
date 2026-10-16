// Striver A2Z DSA - Linked List Easy | Q6
// Problem: Delete Head of Linked List
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Move head pointer to next node, delete old head
// Time Complexity: O(1) | Space Complexity: O(1)

Node* deleteHead(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

void printLL(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = deleteHead(head);
    printLL(head); // 2 -> 3 -> NULL
    return 0;
}
