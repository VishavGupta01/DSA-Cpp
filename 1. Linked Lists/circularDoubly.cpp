#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void printLL(Node* head) {
    Node* temp = head;
    do {
        cout<<temp->data<<"->";
        temp = temp->next;
    } while (temp != head);
    cout<<"Head"<<endl;
}

void insertAtHead(Node* &head, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node* last = head->prev;
    last->next = newNode;
    newNode->next = head;
    head->prev = newNode;
    newNode->prev = last;
    head = newNode;
}

void insertAtEnd(Node* &head, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        return;
    }
    Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    head->prev = newNode;
    last->next = newNode;
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
        cout<<"Index out of Bound inserting at End of List instead!"<<endl;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deletionAtHead(Node* &head) {
    if(head == NULL) {
        cout<<"Empty Linked List!"<<endl;
        return;
    }
    if(head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;
    delete temp;
}

void deletionAtEnd(Node* &head) {
    if(head == NULL) {
        cout<<"Empty Linked List!"<<endl;
        return;
    }
    if(head->next == head) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head->prev;
    temp->prev->next = head;
    head->prev = temp->prev;
    delete temp;
}

void deletionAtPos(Node* &head, int idx) {
    if(head == NULL) {
        cout<<"Empty Linked List!"<<endl;
        return;
    }
    if(idx == 0) {
        deletionAtHead(head);
        return;
    }
    Node* curr = head;
    Node* last = NULL;
    int cnt = 0;
    while(cnt < idx && curr->next != head) {
        last = curr;
        curr = curr->next;
        cnt++;
    }
    if(cnt < idx) {
        cout<<"Index out of Bounds!"<<endl;
        return;
    }
    last->next = curr->next;
    curr->next->prev = last;
    delete curr;
}

int main() {
    Node* node1 = new Node(20);
    Node* head = node1;
    head->next = head->prev = head;
    printLL(head);

    insertAtHead(head, 10);
    insertAtEnd(head, 40);
    insertAtPos(head, 2, 30);
    printLL(head);

    //deletionAtHead(head);
    //deletionAtEnd(head);
    deletionAtEnd(head);
    printLL(head);
    cout<<"Head:"<<head->data<<endl;


    return 0;
}