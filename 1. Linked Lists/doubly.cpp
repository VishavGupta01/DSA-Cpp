#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printLL(Node* head) {
    if(head == NULL) {
        cout<<"Empty Linked List"<<endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(Node* &head, int d) {
    Node* newNode =  new Node(d);
    if(head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    newNode->next = temp;
    temp->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node* &head, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPos(Node* &head, int idx, int d) {
    Node* newNode = new Node(d);
    if(idx == 0) {
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 0;
    while(cnt < idx-1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    if(temp == NULL) {
        cout<<"Index out of Bounds!"<<endl;
        delete newNode;
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deletionAtHead(Node* &head) {
    if(head == NULL) {
        cout<<"Empty List!"<<endl;
        return;
    }

    Node* temp = head;
    if(head->next != NULL) {
        head->next->prev = NULL;
    }
    head = head->next;
    delete temp;
}

void deletionAtEnd(Node* &head){
    if(head == NULL) {
        cout<<"Empty List!"<<endl;
        return;
    }
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

void deletionAtPos(Node* &head, int idx) {
    if(head == NULL) {
        cout<<"Empty List!"<<endl;
        return;
    }
    if(idx == 0) {
        deletionAtHead(head);
        return;
    }
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;
    while(cnt < idx) {
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    if(curr == NULL){
        cout<<"Index out of Bounds!"<<endl;
        return;
    }
    prev->next = curr->next;
    if(curr->next != NULL) curr->next->prev = prev;
    delete curr;
}

int main() {
    Node* node1 = new Node(20);
    Node* head = node1;
    insertAtHead(head, 10);
    insertAtEnd(head,40);
    insertAtPos(head, 2, 30);
    printLL(head);

    // deletion
    //deletionAtHead(head);
    //deletionAtEnd(head);
    deletionAtPos(head,3);
    printLL(head);
    cout<<"Head: "<<head->data<<endl;


    return 0;
}