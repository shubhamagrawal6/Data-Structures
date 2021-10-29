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

void displayList(Node* head){
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

void append(Node** head_ref, int new_data){
    Node* new_node = new Node(new_data);
    Node* last = *head_ref; 
    new_node->next = NULL;
    if(*head_ref == NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

Node* deleteTail(Node* head){
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

Node* deleteHead(Node* head){
    if(!head || !(head->next)){
        return NULL;
    }
    Node* temp = head->next;
    head->next = NULL;
    temp->prev = NULL;
    return temp;
}

Node* deleteNode(Node* head_ref, int x){
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
	Node* head = new Node(7);
    append(&head, 13);
    append(&head, 11);
    append(&head, 8);
    append(&head, 5);
    //7->13->11->8->5->NULL
    displayList(head);

    deleteNode(head, 4); //7->13->11->5->NULL
    cout<<"After deleting "<<endl;
    displayList(head);

    deleteHead(head); //13->11->5->NULL
    cout<<"After deleting "<<endl;
    displayList(head);

    deleteTail(head); //13->11->NULL
    cout<<"After deleting "<<endl;
    displayList(head);
	return 0;
}