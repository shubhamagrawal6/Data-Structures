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

int Ceil(Node* root, int input) { 
    if (root == NULL){ 
        return -1;
    }
    int ans = -1;
    while(root){
        if(root->data == input){
            return input;
        }
        else if(root->data > input){
            ans = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ans;
}

int main(){
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    inorder(root);
    
    cout<<Ceil(root, 3)<<endl;

    return 0;
}