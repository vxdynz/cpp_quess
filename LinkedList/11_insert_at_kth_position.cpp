// Striver A2Z DSA - Linked List Easy | Q11
// Problem: Insert a Node at Kth Position
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Traverse to (k-1)th node and insert new node
// Time Complexity: O(n) | Space Complexity: O(1)

Node* insertAtK(Node* head, int k, int val) {
    Node* newNode = new Node(val);
    if (k == 1) { newNode->next = head; return newNode; }
    Node* curr = head;
    for (int i = 1; i < k - 1 && curr; i++) curr = curr->next;
    if (curr) {
        newNode->next = curr->next;
        curr->next = newNode;
    }
    return head;
}

void printLL(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head = insertAtK(head, 3, 3);
    printLL(head); // 1 -> 2 -> 3 -> 4 -> NULL
    return 0;
}
