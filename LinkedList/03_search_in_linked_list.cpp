// Striver A2Z DSA - Linked List Easy | Q3
// Problem: Search an Element in a Linked List
// Platform: GFG
// Link: https://www.geeksforgeeks.org/search-an-element-in-a-linked-list-iterative-and-recursive/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Traverse and compare each node's data with target
// Time Complexity: O(n) | Space Complexity: O(1)

bool searchElement(Node* head, int target) {
    while (head) {
        if (head->data == target) return true;
        head = head->next;
    }
    return false;
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout << (searchElement(head, 20) ? "Found" : "Not Found") << endl; // Found
    cout << (searchElement(head, 99) ? "Found" : "Not Found") << endl; // Not Found
    return 0;
}
