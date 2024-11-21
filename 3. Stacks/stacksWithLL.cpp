#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

class Stack {
    Node* top;
    public:
    Stack() {
        this->top = NULL;
    }

    void push(int d) {
        Node* newNode = new Node(d);
        if(!newNode) {
            cout<<"Stack Overflow!"<<endl;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(!isEmpty()) {
            cout<<"Element: "<<top->data<<endl;
            top = top->next;
        }
    }

    bool isEmpty() {
        return top==NULL;
    }

    void print() {
        Node* temp = top;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp = temp->next;
        }
    }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.print();
    st.pop();
    st.print();
    return 0;
}