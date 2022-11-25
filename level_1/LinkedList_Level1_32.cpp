#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* next;
};

struct Node* createNode(int data) {
    struct Node* node = new Node();
    node->data = data;
    node->next = NULL;
    return node;
}

void printLinkedList(struct Node* head) {
    struct Node* node = head;
    while (node != NULL) {
        std::cout << node->data << " -> ";
        node = node->next;
    }
    std::cout << "NULL" << std::endl;
}

// This is so simple. Just traverse the linked list and if
// the data in each node matches the key, then increment the
// answer. That's it.
int solve(struct Node* head, int key) {
    struct Node* node = head;
    int ans = 0;
    while (node != NULL) {
        if (node->data == key) {
            ans++;
        }
        node = node->next;
    }
    return ans;
}

void solve() {
    // First create the linked list by reading the input.
    int N;
    std::cin >> N;

    struct Node* dummy = createNode(-1); // Pointer to a dummy head.
    struct Node* node = dummy;
    for (int i = 0; i < N; i++) {
        int data;
        // Read the element.
        std::cin >> data;
        // Create a new node of the linked list.
        struct Node* newNode = createNode(data);
        // Link the newly created node with the previous node (which is `node`).
        node->next = newNode;
        // Assign the running variable `node` to be the newly created node.
        node = newNode;
        // Continue with the next element.
    }
    int key;
    std::cin >> key;
    int ans = solve(dummy->next, key);
    std::cout << ans << std::endl;

}

int main() {
    solve();
}