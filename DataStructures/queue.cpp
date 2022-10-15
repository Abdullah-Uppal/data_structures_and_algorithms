#include <iostream>
using namespace std;

// Node classzz
template<class T>
class Node {
public:
    T data;
    Node<T>* next;
    // constructors
    Node() { data = 0; next = NULL; }
    Node(T d) { data = d; next = NULL; }
    Node(T d, Node<T>* n) { data = d; next = n; }
    ~Node() { }
};

// Stack class
template<class T>
class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
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
template<class T>
Queue<T>::Queue(const Queue<T>& q) {
    
    Node<T> *p = q.front;
    Node<T> *n = NULL;
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
template<class T>
Queue<T>::~Queue() {
    clear();
}

// isEmpty() function
template<class T>
bool Queue<T>::isEmpty() {
    return elementCount == 0;
    // or 
    // return front == NULL;
}

// enqueue function
template<class T>
void Queue<T>::enqueue(int x) {
    Node<T>* t = new Node (x);
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
template<class T>
int Queue<T>::dequeue() {
    int x = -1;
    if (front == NULL)
        cout << "Queue is Empty" << endl;
    else {
        x = front->data;
        Node<T>* t = front;
        front = front->next;
        delete t;
        --elementCount;
    }
    return x;
}

// Display function
template<class T>
void Queue<T>::Display() {
    Node<T>* p = front;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

template<class T>
int Queue<T>::size() {
    return elementCount;
}

// clear function
template<class T>
void Queue<T>::clear() {
    Node<T>* p = front;
    while (front) {
        front = front->next;
        delete p;
        p = front;
    }
    front = rear = NULL;
    elementCount = 0;
}

// reverse function
template<class T>
void Queue<T>::reverse() {
    Node<T> *n = front;
    Node<T> *temp = NULL;
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
    Queue<int> q;
    cout<<"Queue 10"<<endl;
    q.enqueue(10);
    cout<<"Queue 20"<<endl;
    q.enqueue(20);
    cout<<"Queue 30"<<endl;
    q.enqueue(30);

    cout<<"Display Queue 1"<<endl;
    q.Display();
    Queue<int> q2 = q;
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
**/