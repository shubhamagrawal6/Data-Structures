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

void inorder(Node* root, vector<int>& v){
    if(!root){
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}

vector<int> merge(Node* root1, Node* root2){
    vector<int> in1, in2, ans;
    
    inorder(root1, in1);
    inorder(root2, in2);
    
    int n = in1.size(), m = in2.size();
    int i = 0, j = 0;
    while(i<n && j<m){
        if(in1[i] < in2[j]){
            ans.push_back(in1[i++]);
        }

        else if(in1[i] > in2[j]){
            ans.push_back(in2[j++]);
        }

        else{
            ans.push_back(in1[i++]);
            ans.push_back(in2[j++]);
        }
    }

    while(i<n){
        ans.push_back(in1[i++]);
    }

    while(j<m){
        ans.push_back(in2[j++]);
    }

    return ans;
}

int main(){
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(6);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    
    Node* root2 = new Node(2);
    root2->left = new Node(1);
    root2->right = new Node(3);
    root2->right->right = new Node(7);
    root2->right->right->right = new Node(6);

    vector<int> ans = merge(root1, root2);

    for(int i: ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}