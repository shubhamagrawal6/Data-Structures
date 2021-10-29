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

void inOrderRec(Node* root) {
    if (!root){ 
        return;
    }
    inOrderRec(root->left);
    cout<<root->data<<" ";
    inOrderRec(root->right);
}

void inOrderItr(Node* root){
    if(!root){
        cout<<"Empty tree \n";
        return;
    }
    stack<Node*> s;
    Node* curr = root;
    while(curr || !s.empty()){
        if(curr){
            s.push(curr);
            curr = curr->left;
            continue;
        }
        curr = s.top();
        cout<<curr->data<<" ";
        s.pop();
        curr = curr->right;
    }
    cout<<endl;
}

int main() { 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
  
    inOrderRec(root);
    cout<<endl;
    inOrderItr(root); 
    return 0; 
}