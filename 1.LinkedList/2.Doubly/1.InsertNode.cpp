#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void printList(Node* node){
    Node* last;
    cout<<"Traversal in Forward Direction:"<<endl;
    while(node){
        cout<<" "<<node->data<<" ";
        last = node;
        node = node->next;
    }
    cout<<endl;

    cout<<"Traversal in Reverse Direction:"<<endl;
    while(last){
        cout<<" "<<last->data<<" ";
        last = last->prev;
    }
    cout<<endl;
}


void push(Node** head_ref, int new_data){
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if((*head_ref)){
        (*head_ref)->prev = new_node;
    }
    (*head_ref) = new_node;
}

void insertAfter(Node* prev_node, int new_data){
    if(prev_node == NULL){
        cout<<"The given previous node cannot be NULL."<<endl;
        return;
    }

    Node* new_node = new Node(new_data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    new_node->prev = prev_node;

    if(new_node->next){
        new_node->next->prev = new_node;
    } 
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

int main(){  
    Node* head = NULL; 
    append(&head, 6);    
    
    push(&head, 7);    
    push(&head, 1);  
    
    append(&head, 4);  
    insertAfter(head->next, 8);  

    printList(head);
    return 0;  
}