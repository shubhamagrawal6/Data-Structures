#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node * next;
    Node * prev;

    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void displayList(Node *head){
    while(head->next){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data<<endl;

    while(head->prev){
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<head->data<<endl;
}

Node *deleteTail(Node * head){
    if(!head || !(head->next)){
        return NULL;
    }
    Node* curr = head;
    while(curr->next->next){
        curr = curr->next;
    }
    curr->next->prev = NULL;
    curr->next = NULL;
    return head;
}

Node *deleteHead(Node * head){
    if(!head || !(head->next)){
        return NULL;
    }
    Node* temp = head->next;
    head->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* deleteNode(Node *head_ref, int x){
    int k = 1;
    Node* cur = head_ref;
    Node* pre = NULL;
    while(k < x){
        pre = cur; 
        cur = cur->next;
        k++;
    }
    
    if(k == 1){
        head_ref = cur->next;
        return head_ref;
    }

    pre->next = cur->next;
    return head_ref;
}

int main() {
	
	return 0;
}