#include <iostream>
using namespace std;
#define MAX 1000

class Queue { //Insertion at Rear & Deletion at Front
    int* arr;
    int front;
    int rear;

    public:
    Queue() {
        arr = new int[MAX];
        front = rear = 0;
    }

    bool isEmpty();
    bool isFull();
    void enqueue(int d);
    int dequeue();
    int size();
    void print();
    int peek();
};

bool Queue::isEmpty() {
    return front == rear;
}

bool Queue::isFull() {
    return rear == MAX - 1;
}

void Queue::enqueue(int d) {
    if(!isFull()) {
        arr[rear] = d;
        rear++;
    }
}

int Queue::dequeue() {
    if(!isEmpty()) {
        int d = arr[front];
        front++;
        if(front == rear) {
            front = rear = 0;
        }
        return d;
    }
    return -1;
}

int Queue::size() {
    return rear - front;
}

int Queue::peek() {
    if(!isEmpty()) {
        return arr[front];
    }
    return -1;
}

void Queue::print() {
    int i = front;
    while(i < rear) {
        cout<<arr[i]<<endl;
        i++;
    }
}

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.print();

    return 0;
}