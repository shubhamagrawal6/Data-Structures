#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node *head){
    if(head == NULL){
        cout<<"Empty List "<<endl;
        return;
    }

    Node *temp = head; 
    do{
        cout<<temp->data<<endl;
        temp = temp->next;
    }while(temp != head);
}

void push(Node** headref, int data){
    Node* temp = new Node(data);
    temp->next = *headref;

    if(*headref){
        Node* temp = *headref;
        while(temp->next != *headref){
            temp = temp->next;
        }
        temp->next = temp;
    }
    else{
        temp->next = temp;
    }

    *headref = temp;
}

int length(Node* head){
    Node* temp = head;
    int count = 0;

    do{
        temp = temp->next;
        count++;
    }while(temp != head);

    return count;
}

int main(){
    Node* head = new Node(23);
    head->next = head; 

    push(&head, 4);
    push(&head, 3);
    push(&head, 6);
    push(&head, 88);
    push(&head, 1);
    push(&head, 9);
    push(&head, 37);

    cout<<"Length of list is: "<<length(head)<<endl;

    return 0;
}