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

int floor(Node* root, int key) { 
	int ans = -1;
	while(root){
	    if(root->data == key){
	        return root->data;
	    }
	    else if(root->data > key){
	        root = root->left;
	    }
	    else{
	        ans = root->data;
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
    
    cout<<floor(root, 3)<<endl;

    return 0;
}