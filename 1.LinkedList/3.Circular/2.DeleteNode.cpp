#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node *head){
    if(!head){
        cout<<"Empty List "<<endl;
        return;
    }

    Node *temp = head; 
    do{
        cout<<temp->data<<endl;
        temp = temp->next;
    }while(temp != head);
}

void push (Node** head_ref, int data){
    Node* ptr1 = new Node(data);
    ptr1->next = *head_ref;
    if(*head_ref){
        Node* temp = *head_ref;
        while(temp->next != *head_ref){
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else{
        ptr1->next = ptr1;
    }

    *head_ref = ptr1;
}

void deletenode(Node **headref, int item){
    if(*headref == NULL){
        cout<<"Empty List "<<endl;
        return;
    }
    
    if((*headref)->data == item){
        if((*headref)->next == (*headref)){
            delete *headref;
            *headref = NULL;
            return;
        }

        Node *temp  = (*headref)->next;
        while(temp->next != *headref){
            temp = temp->next;
        }
        temp->next = (*headref)->next;
        *headref = temp->next;
        return;
    }
    
    Node *temp  = *headref;
    do{
        if(temp->next->data == item){
            temp->next = temp->next->next;
            break;
        }
        temp = temp->next;
    }while(temp != *headref);
}

int main(){
    Node *itr = new Node(23);
    itr->next = itr; 
    printlist(itr);
    cout<<"test"<<endl;
    
    deletenode(&itr,23);
    printlist(itr);
    cout<<"test"<<endl;

    push(&itr, 4);
    push(&itr, 12);
    push(&itr, 8);
    push(&itr, 1);
    push(&itr, 9);
    push(&itr, 37);
    printlist(itr);
    cout<<"test"<<endl;

    deletenode(&itr, 12);
    printlist(itr);
    cout<<"test"<<endl;
    
    deletenode(&itr, 37);
    printlist(itr);
    cout<<"test"<<endl;

    return 0;
}