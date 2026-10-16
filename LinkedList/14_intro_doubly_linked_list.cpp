// Striver A2Z DSA - Linked List Easy | Q14
// Problem: Introduction to Doubly Linked List - Array to DLL
// Platform: GFG / Striver Sheet
// Link: https://takeuforward.org/data-structure/introduction-to-doubly-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Approach: Create DLL from array setting both next and prev pointers
// Time Complexity: O(n) | Space Complexity: O(n)

Node* createDLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        Node* newNode = new Node(arr[i]);
        curr->next = newNode;
        newNode->prev = curr;
        curr = newNode;
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
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createDLL(arr);
    printDLL(head); // 1 <-> 2 <-> 3 <-> 4 <-> 5
    return 0;
}
