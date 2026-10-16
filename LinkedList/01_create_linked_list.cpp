// Striver A2Z DSA - Linked List Easy | Q1
// Problem: Introduction - Create a Linked List from Array
// Platform: GFG / Striver Sheet
// Link: https://takeuforward.org/linked-list/introduction-to-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Create LL from array and return head
Node* createLL(vector<int>& arr) {
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* curr = head;
    for (int i = 1; i < arr.size(); i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }
    return head;
}

void printLL(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    Node* head = createLL(arr);
    printLL(head); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    return 0;
}
