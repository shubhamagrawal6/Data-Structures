#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left, *right;
    
    Node(int data){
        this->data = data;
        this->left = this->right = NULL;
    }
};

void printLeaves(Node* root){
    if(!root){
        return;
    }
    printLeaves(root->left);
    if(!(root->left) && !(root->right)){
        cout<<root->data<<" ";
        return;
    }
    printLeaves(root->right);
}

void printLeftBoundary(Node* root){
    if(!root || (!(root->right) && !(root->left))){
        return;
    }
    cout<<root->data<<" ";
    if(root->left){
        printLeftBoundary(root->left);
    }
    else if(root->right){
        printLeftBoundary(root->right);
    }
}

void printRightBoundary(Node* root){
    if(!root || (!(root->right) && !(root->left))){
        return;
    }
    if(root->right){
        printRightBoundary(root->right);
    }
    else if(root->left){
        printRightBoundary(root->left);
    }
    cout<<root->data<<" ";
}

void boundaryTraversal(Node* root){
    cout<<root->data<<" ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
    cout<<endl;
}

int main(){
    Node* root = new Node(20); 
    root->left = new Node(8); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    root->right = new Node(22); 
    root->right->right = new Node(25); 

    boundaryTraversal(root);
    return 0;
}