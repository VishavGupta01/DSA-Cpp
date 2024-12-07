#include<iostream>
#include<queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createBT(Node* root) {
    cout << "Enter the Data: "<< endl;
    int d;
    cin >> d;
    root = new Node(d);

    if(d == -1) {
        return NULL;
    }

    cout<<"Enter Data for Left SubTree of "<<d<<endl;
    root->left = createBT(root);
    cout<<"Enter Data for Right SubTree of "<<d<<endl;
    root->right = createBT(root);
    return root;
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}

void inOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root) {
    if(root == NULL) return;
    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(Node* root) {
    if(root == NULL) return;
    inOrder(root->left);
    inOrder(root->right);
    cout<<root->data<<" ";
}

int main() {
    Node* root = createBT(root);
    // 1 2 -1 -1 3 -1 -1
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"InOrder: "<<endl;
    inOrder(root);
    cout<<endl<<"PreOrder: "<<endl;
    preOrder(root);
    cout<<endl<<"PostOrder: "<<endl;
    postOrder(root);
    return 0;
}