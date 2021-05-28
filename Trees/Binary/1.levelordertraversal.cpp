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

void printCurrentLevel(Node* root, int h){
    if(!root){
        return;
    }
    if(h==1){
        cout<<root->data<<" ";
    }
    else{
        printCurrentLevel(root->left, h-1);
        printCurrentLevel(root->right, h-1);
    }
}


void levelOrderRec(Node* root, int h){
    for(int i=1; i<=h; i++){
        printCurrentLevel(root,i);
    }
    cout<<endl;
}

void levelOrderItr(Node *root) {
    if(!root) {
        cout<<"Tree is empty\n";
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
    cout<<endl;
}

int main() { 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 

    levelOrderItr(root); 
    levelOrderRec(root, 3);
    return 0; 
}