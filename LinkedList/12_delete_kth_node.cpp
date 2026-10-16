// Striver A2Z DSA - Linked List Easy | Q12
// Problem: Delete Kth Node in Linked List
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Traverse to (k-1)th node, skip kth node
// Time Complexity: O(n) | Space Complexity: O(1)

Node* deleteKth(Node* head, int k) {
    if (!head) return nullptr;
    if (k == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* curr = head;
    for (int i = 1; i < k - 1 && curr->next; i++) curr = curr->next;
    if (curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
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
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = deleteKth(head, 2);
    printLL(head); // 1 -> 3 -> 4 -> NULL
    return 0;
}
