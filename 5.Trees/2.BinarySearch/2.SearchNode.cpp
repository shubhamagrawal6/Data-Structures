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

bool search(Node* root, int x){
    if(!root){
        return false;
    }
    if(root->data == x){
        return true;
    }
    if(root->data > x){
        return search(root->left, x);
    }
    if(root->data < x){
        return search(root->right, x);
    }
}

int main(){
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    
    cout<<search(root, 3)<<endl;
    cout<<search(root, 5)<<endl;

    return 0;
}
