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

void leftViewUtil(Node* root, int lvl, int& max_level){
    if(!root){
        return;
    }
    if(max_level < lvl){
        cout<<root->data<<" ";
        max_level = lvl;
    }
    leftViewUtil(root->left, lvl+1, max_level);
    leftViewUtil(root->right, lvl+1, max_level);
}

void leftView(Node* root){
    int max_level = 0;
    leftViewUtil(root, 1, max_level);
    cout<<endl;
}

void rightViewUtil(Node* root, int lvl, int& max_level){
    if(!root){
        return;
    }
    if(max_level < lvl){
        cout<<root->data<<" ";
        max_level = lvl;
    }
    rightViewUtil(root->right, lvl+1, max_level);
    rightViewUtil(root->left, lvl+1, max_level);
}

void rightView(Node* root){
    int max_level = 0;
    rightViewUtil(root, 1, max_level);
    cout<<endl;
}

void topView(Node* root){
    map<int, vector<int>> m;
    queue<pair<int, Node*>> q;
    pair<int, Node*> curr;
    int h = 0;
    q.push({h, root});
    while(!q.empty()){
        curr = q.front();
        q.pop();
        h = curr.first;
        m[h].push_back(curr.second->data);
        if(curr.second->left){
            q.push({h-1, curr.second->left});
        }
        if(curr.second->right){
            q.push({h+1, curr.second->right});
        }
    }
    for(auto i=m.begin(); i != m.end(); i++){
        cout<<(i->second)[0]<<" ";
    }
    cout<<endl;
}

void bottomView(Node* root){
    map<int, vector<int>> m;
    queue<pair<int, Node*>> q;
    pair<int, Node*> curr;
    int h = 0;
    q.push({h, root});
    while(!q.empty()){
        curr = q.front();
        q.pop();
        h = curr.first;
        m[h].push_back(curr.second->data);
        if(curr.second->left){
            q.push({h-1, curr.second->left});
        }
        if(curr.second->right){
            q.push({h+1, curr.second->right});
        }
    }
    for(auto i=m.begin(); i != m.end(); i++){
        cout<<(i->second).back()<<" ";
    }
    cout<<endl;
}

int main()  
{ 
    Node * root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(5); 
    root->left->right = new Node(3); 
    root->right->left = new Node(4); 
    root->right->right = new Node(25); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    
    leftView(root);
    rightView(root);
    topView(root);
    bottomView(root);
    return 0; 
} 