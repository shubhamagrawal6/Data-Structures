#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left, *right;
    
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void preOrderRec(Node* root){
    if(!root){ 
        return;
    }
    cout<<root->data<<" ";
    preOrderRec(root->left);
    preOrderRec(root->right);
}

void preOrderItr(Node* root){
    if(!root){
        cout<<"Empty Tree "<<endl;
        return;
    }
    
    stack<Node*> s;
    Node* curr = root;
    while(curr || !s.empty()){
        if(curr){
            cout<<curr->data<<" ";
            s.push(curr);
            curr = curr->left;
            continue;
        }
        curr = s.top();
        s.pop();
        curr = curr->right;
    }
    cout<<endl;
}

int main(){
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);

    preOrderRec(root);
    cout<<endl;
    preOrderItr(root);
    return 0;
}