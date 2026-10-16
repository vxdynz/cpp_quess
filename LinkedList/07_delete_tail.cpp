// Striver A2Z DSA - Linked List Easy | Q7
// Problem: Delete Tail of Linked List
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Traverse to second last node, delete last node
// Time Complexity: O(n) | Space Complexity: O(1)

Node* deleteTail(Node* head) {
    if (!head || !head->next) return nullptr;
    Node* curr = head;
    while (curr->next->next) curr = curr->next;
    delete curr->next;
    curr->next = nullptr;
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
    head = deleteTail(head);
    printLL(head); // 1 -> 2 -> NULL
    return 0;
}
