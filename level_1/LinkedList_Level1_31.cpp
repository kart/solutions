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

void solve(struct Node* head, int D, int N) {
    // We have to remove the last D nodes. How do we do this?
    // We already know the linked list has N elements. So, if
    // we want to remove D elements from the end, then we should
    // have N - D elements left. Right?
    //
    // So, all we have to do is traverse the first (N - D) elements
    // and then set the next pointer to NULL on the (N - D)th element.
    //
    // For ex:
    // If the linked list was 12->24->14->8->241->NULL, then the linked
    // list has 5 elements. Now, if D was 2, then we have to remove the
    // last 2 elements. That is the same as going to '14' and setting
    // 'next' to 'NULL'.
    //
    // Let's first assert that N < D.
    assert(N < D);
    // Assign 'head' to 'node' as we don't want to mess with 'head'.
    struct Node* node = head;
    // We start from '1' but go till N - D (not including N - D). This
    // is because we already start at 'head'.
    for (int i = 1; i < N - D; i++) {
        node = node->next;
    }
    // When the above loop terminates, 'node' will be pointing to just
    // before the end of the final list. So, in the above example, 'node'
    // here will be set to '14'.
    // Now, we simply set node->next to NULL and that will automatically
    // delete '8' and '241'.
    node->next = NULL;
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