// Striver A2Z DSA - Linked List Easy | Q20
// Problem: Intersection of Two Linked Lists
// LeetCode: 160
// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Approach: Two pointers; switch to other list head when reaching end
// They meet at intersection node (or null if no intersection)
// Time Complexity: O(n + m) | Space Complexity: O(1)

Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;
    Node* a = headA;
    Node* b = headB;
    while (a != b) {
        a = a ? a->next : headB;
        b = b ? b->next : headA;
    }
    return a;
}

int main() {
    // Create intersection at node with value 8
    Node* common = new Node(8);
    common->next = new Node(10);
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;
    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = common;
    Node* inter = getIntersectionNode(headA, headB);
    cout << "Intersection at: " << (inter ? inter->data : -1) << endl; // 8
    return 0;
}
