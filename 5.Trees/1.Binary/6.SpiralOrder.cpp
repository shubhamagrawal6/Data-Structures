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

void printCurrentLevel(Node* root, int h, bool ltr){
    if(!root){
        return;
    }
    if(h==1){
        cout<<root->data<<" ";
    }
    else{
        if(ltr){
            printCurrentLevel(root->left, h-1, ltr);
            printCurrentLevel(root->right, h-1, ltr);
        }
        else{
            printCurrentLevel(root->right, h-1, ltr);
            printCurrentLevel(root->left, h-1, ltr);
        }
    }
}

void spiralOrderRec(Node* root, int height){
    bool ltr = true;
    for(int i=1; i<=height; i++){
        ltr = !ltr;
        printCurrentLevel(root,i,ltr);
    }
    cout<<endl;
}

void spiralOrderItr(Node* root){
    if (!root){   
        return;
    }
    stack <Node*> s1;
    stack <Node*> s2;
    
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while (!s1.empty()){
            Node* temp = s1.top();
            s1.pop();
            cout<<temp->data<<" ";

            if (temp->right) s2.push(temp->right);
            if (temp->left) s2.push(temp->left);
        }
        while (!s2.empty()){
            Node* temp = s2.top();
            s2.pop();
            cout<<temp->data<<" ";

            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }
    }
    cout<<endl;
}



int main(){ 
    Node *root = new Node(1); 
    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5); 

    spiralOrderItr(root); 
    spiralOrderRec(root, 3);
    return 0; 
}