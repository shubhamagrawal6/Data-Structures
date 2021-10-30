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

void deleteNode(Node* root, int val){
    Node* del = NULL;
    queue<Node*> q;
    q.push(root);
    Node* temp = NULL;
    
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == val && !del){
            del = temp;
        }
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }

    q.push(root);
    Node* temp2;
    while(!q.empty()){
        temp2 = q.front();
        q.pop();
        if(temp2->left == temp){
            temp2->left = NULL;
            break;
        }
        if(temp2->right == temp){
            temp2->right = NULL;
            break;
        }
        if(temp2->left){
            q.push(temp2->left);
        }
        if(temp2->right){
            q.push(temp2->right);
        }
    }

    if(del){
        int t = temp->data;
        delete(temp);
        del->data = t;
    }
    else{
        cout<<"Not Found"<<endl;
    }
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    levelOrder(root);
    deleteNode(root, 5);
    levelOrder(root);
    return 0;
}