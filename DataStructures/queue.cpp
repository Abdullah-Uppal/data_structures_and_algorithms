#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
};

// Stack class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() { front = rear = NULL; }
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void Display();
    bool isEmpty();
};

// Destructor
Queue::~Queue() {
    Node* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
}

// isEmpty() function
bool Queue::isEmpty() {
    if (front == NULL)
        return true;
    else
        return false;
}

// enqueue function
void Queue::enqueue(int x) {
    Node* t = new Node;
    if (t == NULL)
        cout << "Queue is full" << endl;
    else {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
    }
}

// dequeue function
int Queue::dequeue() {
    int x = -1;
    if (front == NULL)
        cout << "Queue is Empty" << endl;
    else {
        x = front->data;
        Node* t = front;
        front = front->next;
        delete t;
    }
    return x;
}

// Display function
void Queue::Display() {
    Node* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

/**
// Main function
int main() {
    Queue q;
    cout<<"Queue 10"<<endl;
    q.enqueue(10);
    cout<<"Queue 20"<<endl;
    q.enqueue(20);
    cout<<"Queue 30"<<endl;
    q.enqueue(30);

    cout<<"Popping elements from the stack "<<endl;

    while (!q.isEmpty()) {
        cout << "Dequeued " << q.dequeue() << " from queue" << endl;
    }
    return 0;
}
**/