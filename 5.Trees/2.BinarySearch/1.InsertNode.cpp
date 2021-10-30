#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insert(Node* root, int key){
    if(root->data == key){
        return root;
    }
    else if(root->data < key){
        if(root->right == NULL){
            root->right = new Node(key);
        }
        else{
            insert(root->right, key);
        }
    }
    else if(root->data > key){
        if(root->left == NULL){
            root->left = new Node(key);
        }
        else{
            insert(root->left, key);
        }
    }
    return root;
}

int main(){
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    inorder(root);
    
    root = insert(root, 4);
    inorder(root);

    return 0;
}

