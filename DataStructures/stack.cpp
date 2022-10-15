#include <iostream>
using namespace std;

// Node class in c++
template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node()  { data = 0; next = NULL; }
    Node(T d) { data = d; next = NULL; }
    Node(T d, Node* n) { data = d; next = n; }
    // copy constructor
    Node(const Node<T>& n) { data = n.data; next = n.next; }
    // destructor
    ~Node() {}
};

// Stack class in c++
template<class T>
class Stack {
private:
    Node<T>* top;
    int elementCount;

public:
    Stack() { top = NULL; elementCount = 0;}
    // copy constructor
    Stack(const Stack<T>& s);
    ~Stack();
    void push(T x);
    T pop();
    T peek();
    void clear();
    void reverse();
    void Display();
    bool isEmpty();
    int size();
};

// copy constructor; deep copy
template<class T>
Stack<T>::Stack(const Stack& s) {
    Node<T>* p = s.top;
    Node<T>* n = NULL;
    Node<T>* tail = NULL;
    while (p) {
        n = new Node<T>(p->data);
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
template<class T>
Stack<T>::~Stack() {
    clear();
}

// isEmpty() function in c++
template<class T>
bool Stack<T>::isEmpty() {
    return elementCount == 0;
    // or 
    // return top == NULL;
}


// Push function in c++
template<class T>
void Stack<T>::push(T x) {
    Node<T>* t = new Node<T>(x, top);
    if (t == NULL)
        cout << "Stack is full" << endl;
    else {
        top = t;
        ++elementCount;
    }
}

// Pop function in c++
template<class T>
T Stack<T>::pop() {
    T x;
    if (top == NULL) {
        cout << "Stack is Empty" << endl;
        return T();
    }
    else {
        x = top->data;
        Node<T>* t = top;
        top = top->next;
        delete t;
        --elementCount;
    }
    return x;
}

// peek function for stack
template<class T>
T Stack<T>::peek() {
    if (top != NULL)
        return top->data;
    else
        return T();
}

template<class T>
void Stack<T>::clear() {
    Node<T>* p = top;
    while (top) {
        top = top->next;
        delete p;
        p = top;
    }
    elementCount = 0;
}

// reverse function for stack
template<class T>
void Stack<T>::reverse() {
    Node<T> *n = top;
    Node<T> *temp = NULL;
    top = NULL;
    while (n){
        temp = n->next;
        n->next = top;
        top = n;
        n = temp;
    }
}

// Display function in c++
template<class T>
void Stack<T>::Display() {
    Node<T>* p = top;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// size function 
template<class T>
int Stack<T>::size() {
    return elementCount;
}

/**
// Main function in c++
int main() {
    Stack<int> *stk = new Stack<int>();
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
    Stack<int> stk2 = *stk; // copy constructor called
    stk->clear(); // clear the second list
    cout << "After clearing the stack, size is " << stk->size() << endl;

    cout << "Stack 2: ";
    while (!stk2.isEmpty()) {
        cout << "Popped " << stk2.pop() << " from stack" << endl;
    }
    stk2.Display();

    return 0;
}
**/