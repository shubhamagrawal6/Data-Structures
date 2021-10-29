#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node* head){
    if(!head){
        cout<<"Empty List :) "<<endl;
        return;
    }

    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void sortinsert(Node** headref, Node* newnode){
    if(*headref == NULL || (*headref)->data >= newnode->data){
        newnode->next = *headref;
        *headref = newnode;
    }

    else{
        Node* current;
        current = *headref;
        while(current->next != NULL && current->next->data < newnode->data){
            current = current->next;
        }
        newnode->next = current->next;
        current->next = newnode;
    }
}

void insertionsort(Node** headref){
    Node* sorted = NULL;
    Node* current = *headref;

    while(current){
        Node* next = current->next;
        sortinsert(&sorted, current);
        current = next;
    }

    *headref = sorted;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    //7->13->11->8->5->6->NULL
    printlist(head);

    insertionsort(&head); //5->6->7->8->11->13->NULL
    cout<<"Sorted List: "<<endl;
    printlist(head);

    return 0;
}