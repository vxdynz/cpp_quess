// Striver A2Z DSA - Linked List Easy | Q2
// Problem: Find the Length of a Linked List
// Platform: GFG
// Link: https://www.geeksforgeeks.org/find-length-of-a-linked-list-iterative-and-recursive/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Traverse list with counter
// Time Complexity: O(n) | Space Complexity: O(1)

int findLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    cout << "Length: " << findLength(head) << endl; // 4
    return 0;
}
