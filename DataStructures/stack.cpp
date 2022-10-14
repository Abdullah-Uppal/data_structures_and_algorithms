#include <iostream>
using namespace std;

// Node class in c++
class Node {
public:
    int data;
    Node* next;
    Node()  { data = 0; next = NULL; }
    Node(int d) { data = d; next = NULL; }
    Node(int d, Node* n) { data = d; next = n; }
    // copy constructor
    Node(const Node& n) { data = n.data; next = n.next; }
    // destructor
    ~Node() {}
};

// Stack class in c++
class Stack {
private:
    Node* top;
    int elementCount;

public:
    Stack() { top = NULL; elementCount = 0;}
    // copy constructor
    Stack(const Stack& s);
    ~Stack();
    void push(int x);
    int pop();
    int peek();
    void clear();
    void reverse();
    void Display();
    bool isEmpty();
    int size();
};

// copy constructor; deep copy
Stack::Stack(const Stack& s) {
    Node* p = s.top;
    Node* n = NULL;
    Node* tail = NULL;
    while (p) {
        n = new Node(p->data);
        // if it is the first node, update top
        if (tail == NULL) {
            top = tail = n;
        } else {
            // add at end
            tail->next = n;
        }
        // update tail
        tail = n;
        p = p->next;
    }

    elementCount = s.elementCount;
}

// Destructor
Stack::~Stack() {
    clear();
}

// isEmpty() function in c++
bool Stack::isEmpty() {
    return elementCount == 0;
    // or 
    // return top == NULL;
}


// Push function in c++
void Stack::push(int x) {
    Node* t = new Node(x, top);
    if (t == NULL)
        cout << "Stack is full" << endl;
    else {
        top = t;
        ++elementCount;
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
        --elementCount;
    }
    return x;
}

// peek function for stack
int Stack::peek() {
    if (top != NULL)
        return top->data;
    else
        return -1;
}

void Stack::clear() {
    Node* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
    elementCount = 0;
}

// reverse function for stack
void Stack::reverse() {
    Node *n = top;
    Node *temp = NULL;
    top = NULL;
    while (n){
        temp = n->next;
        n->next = top;
        top = n;
        n = temp;
    }
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

// size function 
int Stack::size() {
    return elementCount;
}

/**
// Main function in c++
int main() {
    Stack *stk = new Stack();
    cout<<"Push 10"<<endl;
    stk->push(10);
    cout<<"Push 20"<<endl;
    stk->push(20);
    cout<<"Push 30"<<endl;
    stk->push(30);
    cout << "Stack: ";
    stk->Display();
    // reverse the stack
    stk->reverse();
    cout << "reversed stack is : ";
    stk->Display();

    cout<<"Popping elements from the stack "<<endl;

    cout << "Peeking the stack " << stk->peek() << endl;
    Stack stk2 = *stk; // copy constructor called
    stk->clear(); // clear the second list
    cout << "After clearing the stack, size is " << stk->size() << endl;

    cout << "Stack 2: ";
    while (!stk2.isEmpty()) {
        cout << "Popped " << stk2.pop() << " from stack" << endl;
    }
    stk2.Display();

    return 0;
}
// **/