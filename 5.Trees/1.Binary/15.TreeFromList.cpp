#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printlist(Node* head){
    if(!head){
        cout<<"Empty List :) "<<endl;
    }

    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void inorder(TreeNode* root){
    if(!root){ 
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void convert(Node* head, TreeNode*& root){
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    Node* lcurr = head->next;
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(lcurr){
            curr->left = new TreeNode(lcurr->data);
            q.push(curr->left);
            lcurr = lcurr->next;
            if(lcurr){
                curr->right = new TreeNode(lcurr->data);
                q.push(curr->right);
                lcurr = lcurr->next;
            }
        }
    }
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    //7->13->11->8->5->NULL
    printlist(head);

    TreeNode* root;
    convert(head, root);

    inorder(root);

    return 0;
}

