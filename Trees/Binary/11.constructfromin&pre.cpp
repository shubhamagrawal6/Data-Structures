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

Node* constructTreeUtil(int in[], int pre[], int inStart, int inEnd, unordered_map<int,int>& m, int& preIndex){
    if(inStart > inEnd){
        return NULL;
    }
    int curr = pre[preIndex++];
    Node* root = new Node(curr);
    if(inStart == inEnd){
        return root;
    }
    int inIndex = m[curr];
    root->left = constructTreeUtil(in, pre, inStart, inIndex-1, m, preIndex);
    root->right = constructTreeUtil(in, pre, inIndex+1, inEnd, m, preIndex);
    return root;
}

Node* constructTree(int in[], int pre[], int n){
    if(n<=0){
        return NULL;
    }
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[in[i]] = i;
    }
    int preIndex = 0;
    return constructTreeUtil(in, pre, 0, n-1, m, preIndex);
}

int main() { 
    int in[] = {4,2,6,5,7,1,3}; 
    int pre[] = {1,2,4,5,6,7,3}; 

    Node* root = constructTree(in, pre, 7); 
    inorder(root); 
    return 0;
}