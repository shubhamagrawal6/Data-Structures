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

void inorder(Node* root){
    if(!root){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* constructTreeUtil(int pre[], int post[], int l, int r, int n, int& preIndex, map<int,int>& m){
    if(preIndex >= n || l > r){
        return NULL;
    }

    Node* root = new Node(pre[preIndex++]);
    
    if(l == r){
        return root;
    }

    int postIndex = m[pre[preIndex]];

    if(postIndex <= r){
        root->left = constructTreeUtil(pre, post, l, postIndex, n, preIndex, m);
        root->right = constructTreeUtil(pre, post, postIndex+1, r, n, preIndex, m);
    }
    return root;
}

Node* constructTree(int pre[], int post[], int n){
    if(n<=0){
        return NULL;
    }
    map<int, int> m;
    int preIndex = 0;
    for(int i=0; i<n; i++){
        m[post[i]] = i;
    }
    return constructTreeUtil(pre, post, 0, n-1, n, preIndex, m);
}


int main () {  
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};  
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};  
    int size = 9;  

    Node *root = constructTree(pre, post, size);  
  
    inorder(root);  
  
    return 0;  
} 