#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data) {
        this-> data = data;
        this-> next = NULL;
    }
};

void printLL(Node* head) {
    if(head == NULL) {
        cout<<"Empty List"<<endl;
        return;
    }
    Node* temp = head;
    do {
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp != head);
    cout<<"head"<<endl;
}

void insertAtHead(Node* &head, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        return;
    }
    Node* temp = head;
    do {
        temp = temp->next;
    } while (temp->next != head);
    temp->next = newNode;
    newNode->next = head;
}

void insertAtPos(Node* &head, int idx, int d) {
    if(idx == 0) {
        insertAtHead(head,d);
        return;
    }
    Node* newNode = new Node(d);
    int cnt = 1;
    Node* temp = head;
    while(cnt < idx && temp->next != head) {
        temp = temp->next;
        cnt++;
    }
    if(cnt < idx) {
        cout<<"Index out of Bound! Inserting at End of List instead!"<<endl;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtHead(Node* &head){
    if(head == NULL) {
        cout<<"Empty Linked List!"<<endl;
        return;
    }
    if(head->next == head) { //Single Element
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    head = head->next;
}

void deleteAtEnd(Node* &head) {
    if(head == NULL) {
        cout<<"Empty Linked List!"<<endl;
        return;
    }
    if(head->next == head) { //Single Element
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != head) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = head;
}

void deleteAtPos(Node* &head, int idx) {
    if(head == NULL) {
        cout<<"Empty Linked List!"<<endl;
        return;
    }
    if(idx == 0) {
        deleteAtHead(head);
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;
    while(cnt < idx && curr->next != head) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(cnt < idx) {
        cout<<"Index out of Bounds!"<<endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

int main() {
    Node* node1 = new Node(20);
    Node* head = node1;
    node1->next = head;
    printLL(head);

    insertAtHead(head,10);
    printLL(head);
    insertAtEnd(head,40);
    printLL(head);
    insertAtPos(head,2,30);
    printLL(head);

    //deleteAtHead(head);
    //deleteAtEnd(head);
    deleteAtPos(head,3);
    printLL(head);
    cout<<head->data;

    return 0;
}