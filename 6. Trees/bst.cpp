#include <iostream>
#include <queue>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d) { // TC -> O(log n)
    if(root == NULL) { // Base Case
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right,d);
    } else {
        root->left = insertIntoBST(root->left,d);
    }
    return root;
}

void levelOrderTraversal(Node* root) {
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
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
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) {
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

bool searchInBSTrec(Node* root, int key) { // TC -> O(n)
    if(root == NULL) return false;
    if(root->data == key) return true;
    else if (root->data > key) return searchInBST(root->left,key);
    else return searchInBST(root->right,key);
}

bool searchInBSTitr(Node* root, int key) {
    // TC -> O(h) [h = depth of the Tree]
    if(root == NULL) return false;
    Node* temp = root;
    while(temp != NULL) {
        if(temp->data == key) return true;
        else if (temp->data > key) temp = temp->left;
        else temp = temp->right;
    }
    return false;
}

int minInBST(Node* root) {
    if(root == NULL) return -1;
    Node* temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }
    return temp->data;
}

int maxInBST(Node* root) {
    if(root == NULL) return -1;
    Node* temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }
    return temp->data;
}

int predecessor(Node* root, int key) {
    if(root == NULL) return -1;
    int Pred = -1;
    Node* temp = root;
    while(temp != NULL) {
        if(temp->data >= key) {
            temp = temp->left;
        } else {
            Pred = temp->data;
            temp = temp->right;
        }
    }
    return Pred;
}

int successor(Node* root, int key) {
    if(root == NULL) return -1;
    int succ = -1;
    Node* temp = root;
    while(temp != NULL) {
        if(temp->data <= key) {
            temp = temp->left;
        } else {
            succ = temp->data;
            temp = temp->right;
        }
    }
    return succ;
}

Node* deletion(Node* root, int key) {
    if(root == NULL) return root;
    if(root->data == key) {
        // 0 Child
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // 1 Child
        // Left Child
        if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Right Child
        if(root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 Child
        if(root->left != NULL && root->right != NULL) {
            int min = minInBST(root->right); // Replacing with Min from right SubTree
            root->data = min;
            root->right = deletion(root->right, min);
            return root;

            // Replacing with Max from Left SubTree
            // int max = maxInBST(root->left);
            // root->data = max;
            // root->left = deletion(root->left,max);
            // return root;
        }
    } else if(root->data > key) {
        root->left = deletion(root->left,key);
        return root;
    } else {
        root->right = deletion(root->right, key);
        return root;
    }
}

void takeInput(Node* &root) {
    int data;
    cin>>data;
    while(data != -1) {
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

int main() {
    Node* root = NULL;
    cout<<"Enter Data for BST: "<<endl;
    takeInput(root);

    cout<<endl<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    cout<<endl<<"InOrder Traversal: "<<endl;
    inOrder(root);

    cout<<endl<<"PreOrder Traversal: "<<endl;
    preOrder(root);

    cout<<endl<<"PostOrder Traversal: "<<endl;
    postOrder(root);

    return 0;
}