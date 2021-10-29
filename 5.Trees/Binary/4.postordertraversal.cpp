#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *left, *right;
        Node(int data){
            this->data = data;
            this->right = this->left = NULL;
        }
};

void postOrderRec(Node* root) {
    if (!root){
        return;
    }
    postOrderRec(root->left);
    postOrderRec(root->right);
    cout<<root->data<<" ";
}

void postOrderItr(Node* root){
    if(!root){
        cout<<"Tree is empty\n";
        return;
    }
    vector<int> ans;
    stack<Node*> s;
    Node* curr = root;
    while(curr || !s.empty()){
        if(curr){
            ans.push_back(curr->data);
            s.push(curr);
            curr = curr->right;
            continue;
        }
        curr = s.top();
        s.pop();
        curr = curr->left;
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main() { 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 
  
    postOrderRec(root);
    cout<<endl;
    postOrderItr(root); 
    return 0; 
}