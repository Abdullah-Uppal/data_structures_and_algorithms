#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    // constructors
    Node() { data = 0; next = NULL; }
    Node(int d) { data = d; next = NULL; }
    Node(int d, Node* n) { data = d; next = n; }
    ~Node() { }
};

// Stack class
class Queue {
private:
    Node* front;
    Node* rear;
    int elementCount;

public:
    Queue() { front = rear = NULL; elementCount = 0; }
    // copy constructor
    Queue(const Queue& q);
    ~Queue();
    void enqueue(int x);
    int dequeue();
    void Display();
    bool isEmpty();
    int size();
    void clear();
    void reverse();
};

// copy constructor; deep copy
Queue::Queue(const Queue& q) {
    
    Node *p = q.front;
    Node *n = NULL;
    front = rear = NULL;
    while (p) {
        n = new Node(p->data);
        // if it is the first node, update top
        if (rear == NULL) {
            front = rear = n;
        } else {
            // add at end
            rear->next = n;
        }
        // update tail/rear
        rear = n;
        p = p->next;
    }

    elementCount = q.elementCount;
}

// Destructor
Queue::~Queue() {
    clear();
}

// isEmpty() function
bool Queue::isEmpty() {
    return elementCount == 0;
    // or 
    // return front == NULL;
}

// enqueue function
void Queue::enqueue(int x) {
    Node* t = new Node (x);
    if (t == NULL)
        cout << "Queue is full" << endl;
    else {
        if (front == NULL)
            front = rear = t;
        else {
            rear->next = t;
            rear = t;
        }
        ++elementCount;
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
        --elementCount;
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

int Queue::size() {
    return elementCount;
}

// clear function
void Queue::clear() {
    Node* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
    front = rear = NULL;
    elementCount = 0;
}

// reverse function
void Queue::reverse() {
    Node *n = front;
    Node *temp = NULL;
    rear = front;
    front = NULL;
    while (n){
        temp = n->next;
        n->next = front;
        front = n;
        n = temp;
    }
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

    cout<<"Display Queue 1"<<endl;
    q.Display();
    Queue q2 = q;
    cout<<"Display Queue 2"<<endl;
    q2.Display();
    
    q2.reverse();
    cout << "Queue 2 reversed: " << endl;
    q2.Display();
    
    
    cout << "queue has been reversed" << endl;

    cout<<"Popping elements from the stack "<<endl;

    while (!q.isEmpty()) {
        cout << "Dequeued " << q.dequeue() << " from queue" << endl;
    }
    return 0;
}
// **/