// Striver A2Z DSA - Linked List Easy | Q17
// Problem: Reverse a Doubly Linked List
// Platform: GFG / Striver Sheet
// Link: https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Approach: Swap next and prev for every node
// Time Complexity: O(n) | Space Complexity: O(1)

Node* reverseDLL(Node* head) {
    Node* curr = head;
    Node* temp = nullptr;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        head = curr;
        curr = curr->prev;
    }
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
    Node* head = reverseDLL(n1);
    printDLL(head); // 4 <-> 3 <-> 2 <-> 1
    return 0;
}
