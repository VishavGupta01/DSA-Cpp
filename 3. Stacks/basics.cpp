#include <iostream>
#include <climits>
using namespace std;
#define MAX 100

class Stack {
    public:
    int top;
    int arr[MAX];

    Stack() {
        top = -1;
    }
    void push(int d);
    int pop();
    int peek();
    void print();
    bool isEmpty();
    bool isFull();
};

void Stack::push(int d) {
    if(top == MAX-1) {
        cout<<"Stack Overflow!"<<endl;
        return;
    } else {
        top++;
        arr[top] = d;
        cout<<"Pushed!"<<endl;
    }
}

int Stack::pop() {
    if(top < 0) {
        cout<<"Stack Underflow!"<<endl;
        return INT_MIN;
    } else {
        int data = arr[top];
        top--;
        return data;
    }
}

int Stack::peek() {
    if(top < 0) {
        cout<<"Stack Underflow!"<<endl;
        return INT_MIN;
    } else {
        return arr[top];
    }
}

bool Stack::isEmpty() {
    return (top < 0);
}

bool Stack::isFull() {
    return (top == MAX-1);
}

void Stack::print() {
    if(top < 0) {
        cout<<"Stack Underflow!"<<endl;
        return;
    }
    int temp = top;
    while(temp >= 0) cout<<arr[temp--]<<endl;
}

int main() {
    Stack st;
    st.pop();
    st.push(10);
    st.push(20);
    st.push(30);
    cout<<st.peek()<<endl;
    st.print();
    cout<<st.top<<endl;
    cout<<st.pop()<<endl;
    cout<<st.isFull()<<endl;
    cout<<st.isEmpty()<<endl;
    return 0;
}