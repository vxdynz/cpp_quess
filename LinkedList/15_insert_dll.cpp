// Striver A2Z DSA - Linked List Easy | Q15
// Problem: Insert a Node in Doubly Linked List (at head/tail/position)
// Platform: GFG / Striver Sheet

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* insertAtHeadDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    if (head) head->prev = newNode;
    return newNode;
}

Node* insertAtTailDLL(Node* head, int val) {
    Node* newNode = new Node(val);
    if (!head) return newNode;
    Node* curr = head;
    while (curr->next) curr = curr->next;
    curr->next = newNode;
    newNode->prev = curr;
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
    Node* head = new Node(2);
    head->next = new Node(3);
    head->next->prev = head;
    head = insertAtHeadDLL(head, 1);
    head = insertAtTailDLL(head, 4);
    printDLL(head); // 1 <-> 2 <-> 3 <-> 4
    return 0;
}
