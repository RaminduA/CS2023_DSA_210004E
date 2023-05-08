#include <iostream>
using namespace std;

#define MAX_SIZE 100 // maximum capacity of the stack

class Stack {
    private:
        int top; // index of the topmost element in the stack
        int arr[MAX_SIZE]; // array to store the elements of the stack
    public:
        Stack() { // constructor to initialize the top index to -1
            top = -1;
        }

        bool isEmpty() { // function to check if the stack is empty
            return top == -1;
        }

        bool isFull() { // function to check if the stack is full
            return top == MAX_SIZE - 1;
        }

        void push(int x) { // function to add an element to the top of the stack
            if (isFull()) { // if the stack is full, print an error message
                cout << "Stack Overflow\n";
            } else {
                top++; // increment the top index
                arr[top] = x; // add the element to the top of the stack
            }
        }

        int pop() { // function to remove and return the topmost element from the stack
            if (isEmpty()) { // if the stack is empty, print an error message
                cout << "Stack Underflow\n";
                return -1;
            } else {
                int val = arr[top]; // store the topmost element in a variable
                top--; // decrement the top index
                return val; // return the stored topmost element
            }
        }

        int peek() { // function to return the value of the topmost element without removing it
            if (isEmpty()) { // if the stack is empty, print an error message
                cout << "Stack Underflow\n";
                return -1;
            } else {
                return arr[top]; // return the value of the topmost element
            }
        }
};

int main() {
    Stack s; // create a new stack object
    s.push(1); // add an element to the top of the stack
    s.push(2);
    s.push(3);
    cout << s.pop() << endl; // remove and print the topmost element from the stack
    cout << s.pop() << endl;
    cout << s.peek() << endl; // print the value of the topmost element without removing it
    s.push(4);
    cout << s.peek() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl; // try to remove an element from an empty stack, which results in an error message
    return 0;
}
