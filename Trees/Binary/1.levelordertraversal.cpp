#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left, *right;
        Node(int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};

void levelorder(Node *root) {
    if(!root) {
        cout<<"Tree is empty\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        cout<<temp->data<<endl;
        q.pop();
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

int main() { 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 

    cout << "Level order traversal is: \n"; 
    levelorder(root); 
    
    return 0; 
}