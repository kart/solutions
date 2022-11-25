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

// This is very similar to challenge 31, but instead of removing
// the last D nodes, we remove the first D nodes.
void solve(struct Node* dummy, int D, int N) {
    // We have to remove the first D nodes. How do we do this?
    // Quite simple -- traverse the first D nodes, then you simply assign
    // dummy head's next to the (D + 1)th node.
    //
    // For ex:
    // If the linked list was dummy->12->24->14->8->241->NULL, then the linked
    // list has 5 elements. Now, if D was 2, then we have to remove the
    // first 2 elements. So, we need to simply set dummy->next to '14'.
    //
    // Assign 'head' (which is dummy->next) to 'node'.
    struct Node* node = dummy->next;
    // We start from '1' but go till D (not including D). This
    // is because we already start at 'head'.
    for (int i = 1; i < D; i++) {
        node = node->next;
    }
    // When the above loop terminates, 'node' will be pointing to just
    // after the Dth node. So, in the above example, 'node' here will
    // be set to '14'.
    // Now, we simply set dummy->next to node and that will automatically
    // delete '12' and '24'.
    dummy->next = node;
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
    // Now read 'D' which is the number of nodes to delete from the end.
    int D;
    std::cin >> D;

    // At this point, we've read all the elements and constructed the linked list.
    // Because we have a dummy node, the real linked list starts from dummy->next.
    // Let's print it to be sure.
    printLinkedList(dummy->next);

    // Now, let's solve the actual problem.
    solve(dummy->next, D, N);

    // Now, print the list.
    printLinkedList(dummy->next);
}

int main() {
    solve();
}