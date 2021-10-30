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

void verticalOrder(Node* root){
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
        for(auto j: i->second){
            cout<<j<<" ";
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
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    verticalOrder(root); 
    return 0; 
}