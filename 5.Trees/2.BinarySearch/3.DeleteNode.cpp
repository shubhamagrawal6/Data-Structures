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

Node* Delete(Node* root, int x){
    if(!root){
        return root;
    }

    if(root->data == x){
        if(!root->left){
            return root->right;
        }

        else if(!root->right){
            return root->left;
        }

        else{
            Node* curr = root->left;
            Node* prev = root->left;
            if(!curr->right){
                root->data = curr->data;
                root->left = Delete(root->left, curr->data);
            }

            else{
                while(curr->right){
                    prev = curr;
                    curr = curr->right;
                }
                root->data = curr->data;
                prev->right = curr->left;
            }
        }
    }
    
    else if(root->data < x){
        root->right = Delete(root->right, x);
    }

    else if(root->data > x){
        root->left = Delete(root->left, x);
    }

    return root;
}

int main(){
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    root->right->right = new Node(6);
    inorder(root);
    
    root = Delete(root, 3);
    inorder(root);

    return 0;
}