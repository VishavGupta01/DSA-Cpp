#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void printLL(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<< temp -> data <<"->";
        temp = temp-> next;
    }
    cout<<"NULL"<<endl;
}

void insertAtHead(Node* &head, int d) {
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int d) {
    Node* newNode = new Node(d);
    if(head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp-> next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtPosition(Node* &head, int pos, int d){
    Node* newNode = new Node(d);
    if(pos == 0) {
        insertAtHead(head,d);
        return;
    }

    Node* temp = head;
    int counter = 0;
    while(counter < pos) {
        temp = temp->next;
        counter++;
    }
    if(temp == NULL) {
        cout<<"Index Out of Bounds!"<<endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void deletionAtHead(Node* &head) {
    if(head == NULL) {
        cout<<"Empty LL"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deletionAtTail(Node* &head) {
    if(head == NULL) {
        cout<<"Empty LL"<<endl;
        return;
    }

    if(head->next == NULL){
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
        cout<<"Empty LL"<<endl;
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
    if(curr == NULL) {
        cout<<"Index Out of Bounds!"<<endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}

int main() {
    Node* node1 = new Node(20);
    Node* head = node1;

    //Insertion
    insertAtHead(head,10);
    cout<<"Head: "<<head->data<<endl;
    insertAtEnd(head, 40);
    insertAtPosition(head, 1 , 30);
    printLL(head);

    //Deletion
    //deletionAtHead(head);
    //deletionAtTail(head);
    //deletionAtPos(head, 4);
    //cout<<"Head: "<<head->data<<endl;
    //printLL(head);

    return 0;
}