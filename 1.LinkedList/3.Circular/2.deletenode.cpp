#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node *head) {
    
    if(head == NULL){
        cout<<"Empty List \n";
        return;
    }

    Node *temp = head; 
    //Since it is circular linked list the next element will only be null if list is empty

    do {
        cout<<temp->data<<endl;
        temp = temp->next;
    }while(temp != head);

}

void push (Node** head_ref, int data) {
    Node* ptr1 = new Node(data);
    ptr1->next = *head_ref;
    // If linked list is not NULL then set the next of last node
    if (*head_ref != NULL) {
        // Find the node before head and update next of it
        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;
    
    *head_ref = ptr1;
}

void deletenode(Node **headref, int item) {
    //If list is empty
    if(*headref == NULL){
        cout<<"Empty List \n";
        return;
    }
    
    //If node to be deleted is at head
    if((*headref)->data == item){
        //If list is a self loop
        if((*headref)->next == (*headref)){
            delete *headref;
            *headref = NULL;
            return;
        }

        else{
            Node *temp  = (*headref)->next;
            while(temp->next != *headref){
                temp = temp->next;
            }
            temp->next = (*headref)->next;
            *headref = temp->next;
            return;
        }
    }
    
    //If node to be deleted is anywhere except head
    Node *temp  = *headref;
    do {
        if(temp->next->data == item){
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }while(temp != *headref);
}

int main(){
    Node *itr = new Node(23);
    itr->next = itr; // Making a Circular Linked List :) 
    printlist(itr);
    cout<<"test\n";
    
    deletenode(&itr,23);
    printlist(itr);
    cout<<"test\n";

    push(&itr, 4);
    push(&itr, 12);
    push(&itr, 8);
    push(&itr, 1);
    push(&itr, 9);
    push(&itr, 37);
    printlist(itr);
    cout<<"test\n";

    deletenode(&itr, 12);
    printlist(itr);
    cout<<"test\n";
    
    deletenode(&itr, 37);
    printlist(itr);
    cout<<"test\n";

    return 0;
}