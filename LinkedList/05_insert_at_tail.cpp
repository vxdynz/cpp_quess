// Striver A2Z DSA - Linked List Easy | Q5
// Problem: Insert a Node at the Tail of Linked List
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Traverse to last node, attach new node
// Time Complexity: O(n) | Space Complexity: O(1)

Node* insertAtTail(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    return head;
}

void printLL(Node* head) {
    while (head) { cout << head->data << " -> "; head = head->next; }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head = insertAtTail(head, 3);
    printLL(head); // 1 -> 2 -> 3 -> NULL
    return 0;
}
