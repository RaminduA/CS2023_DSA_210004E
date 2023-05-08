#include <iostream>
using namespace std;

// Define a structure for the node
struct Node {
    int data;
    Node* next;
};

// Define a structure for the stack
struct Stack {
    Node* head; // Pointer to the head of the linked list
    Node* top; // Pointer to the top of the stack
};

// Initialize the stack
void initialize(Stack& S) {
    S.head = NULL; // Initializing head pointer to NULL
    S.top = NULL; // Initializing top pointer to NULL
}

// Check if the stack is empty
bool is_empty(Stack S) {
    return S.top == NULL; // Return true if top pointer is NULL, else false
}

// Push an element to the top of the stack
void push(Stack& S, int data) {
    Node* n = new Node; // Create a new node
    n->data = data; // Assign data to the node
    n->next = NULL; // Initialize next pointer to NULL
    if (is_empty(S)) { // If stack is empty
        S.head = n; // New node is the head of the linked list
        S.top = n; // New node is also the top
    }
    else { // If stack is not empty
        S.top->next = n; // Link the new node to the previous top node
        S.top = n; // Update the top pointer to the new node
    }
}

// Pop an element from the top of the stack
int pop(Stack& S) {
    if (is_empty(S)) { // If stack is empty
        cout << "Stack Underflow" << endl; // Print error message
        return -1; // Return -1 as error code
    }
    else { // If stack is not empty
        int x = S.top->data; // Store the data of the top node
        if (S.top == S.head) { // If there's only one node
            S.top = NULL; // Update the top pointer to NULL
            S.head = NULL; // Update the head pointer to NULL
        }
        else { // If there are more than one nodes
            Node* tmp = S.head; // Initialize a temporary pointer to the head of the linked list
            while (tmp->next != S.top) { // Traverse the linked list till the node previous to top
                tmp = tmp->next;
            }
            tmp->next = NULL; // Set the next pointer of the previous node to NULL
            S.top = tmp; // Update the top pointer to the previous node
        }
        return x; // Return the popped element
    }
}


int main() {
    Stack S; // Declare a stack variable
    initialize(S); // Initialize the stack
    push(S, 5); // Push 5 to the stack
    push(S, 10); // Push 10 to the stack
    push(S, 15); // Push 15 to the stack
    cout << pop(S) << endl; // Output: 15
    cout << pop(S) << endl; // Output: 10
    cout << pop(S) << endl; // Output: 5
    cout << pop(S) << endl; // Output: Stack Underflow
    return 0; // Exit program
}
