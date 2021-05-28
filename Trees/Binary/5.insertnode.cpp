#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node *right, *left;
        Node(int data){
            this->data = data;
            this->right = this->left = NULL;
        }
};

void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr = q.front();
        cout<<curr->data<<" ";
        q.pop();
        if(curr->left != NULL) {
            q.push(curr->left);
        }
        if(curr->right != NULL) {
            q.push(curr->right);
        }
    }
    cout<<endl;
}

void insertNode(Node* root, int val){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp->left){
            q.push(temp->left);
        }
        else{
            temp->left = new Node(val);
            break;
        }
        if(temp->right){
            q.push(temp->right);
        }
        else{
            temp->right = new Node(val);
            break;
        }
    }
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    levelOrder(root);
    insertNode(root, 6);
    levelOrder(root);
    return 0;
}