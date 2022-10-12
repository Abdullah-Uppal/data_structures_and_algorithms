#include <iostream>
using namespace std;

// Node class in c++
class Node {
public:
    int data;
    Node* next;
};

// Stack class in c++
class Stack {
private:
    Node* top;

public:
    Stack() { top = NULL; }
    ~Stack();
    void push(int x);
    int pop();
    void Display();
    bool isEmpty();
};

// Destructor
Stack::~Stack() {
    Node* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
}

// isEmpty() function in c++
bool Stack::isEmpty() {
    if (top == NULL)
        return true;
    else
        return false;
}


// Push function in c++
void Stack::push(int x) {
    Node* t = new Node;
    if (t == NULL)
        cout << "Stack is full" << endl;
    else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Pop function in c++
int Stack::pop() {
    int x = -1;
    if (top == NULL)
        cout << "Stack is Empty" << endl;
    else {
        x = top->data;
        Node* t = top;
        top = top->next;
        delete t;
    }
    return x;
}

// Display function in c++
void Stack::Display() {
    Node* p = top;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/**
// Main function in c++
int main() {
    Stack stk;
    cout<<"Push 10"<<endl;
    stk.push(10);
    cout<<"Push 20"<<endl;
    stk.push(20);
    cout<<"Push 30"<<endl;
    stk.push(30);
    cout << "Stack: ";
    stk.Display();

    cout<<"Popping elements from the stack "<<endl;

    while (!stk.isEmpty()) {
        cout << "Popped " << stk.pop() << " from stack" << endl;
    }
    stk.Display();
    return 0;
}
**/
