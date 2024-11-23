#include <iostream>
using namespace std;
#define MAX 10

class CircularQueue {
    int* arr;
    int front;
    int rear;

    public:
    CircularQueue() {
        arr = new int[MAX];
        front = rear = -1;
    }

    void enq(int d);
    int deq();
    bool isFull();
    bool isEmpty();
};

bool CircularQueue::isFull() {
    if(front == (rear + 1) % MAX) return true;
    return false;
}

bool CircularQueue::isEmpty() {
    if(front == -1) return true;
    return false;
}

void CircularQueue::enq(int data) {
    if(isFull()) {
        cout<<"Queue Overflow!"<<endl;
        return;
    }
    if(rear == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    arr[rear] = data;
}

int CircularQueue::deq() {
    if(isEmpty()) {
        cout<<"Queue Underflow!"<<endl;
        return -1;
    }
    int d = arr[front];
    if (front == rear) front = rear = -1;
    else {
        front = (front + 1) % MAX;
    }
    return d;
}

int main() {
    CircularQueue cq;
    cout<<cq.isEmpty()<<endl;
    cq.enq(10);
    cq.enq(20);
    cq.enq(30);
    cout<<cq.deq()<<endl;
    cout<<cq.deq()<<endl;
    cout<<cq.deq()<<endl;
    cout<<cq.isEmpty()<<endl;
    return 0;
}