// Striver A2Z DSA - Linked List Easy | Q16
// Problem: Delete a Node in Doubly Linked List
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Approach: Update prev->next and next->prev to bypass node
// Time Complexity: O(n) to find | O(1) to delete

Node* deleteNodeDLL(Node* head, int val) {
    Node* curr = head;
    while (curr && curr->data != val) curr = curr->next;
    if (!curr) return head;
    if (curr->prev) curr->prev->next = curr->next;
    else head = curr->next; // deleting head
    if (curr->next) curr->next->prev = curr->prev;
    delete curr;
    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* n1 = new Node(1); Node* n2 = new Node(2);
    Node* n3 = new Node(3); Node* n4 = new Node(4);
    n1->next = n2; n2->prev = n1;
    n2->next = n3; n3->prev = n2;
    n3->next = n4; n4->prev = n3;
    Node* head = deleteNodeDLL(n1, 3);
    printDLL(head); // 1 <-> 2 <-> 4
    return 0;
}
