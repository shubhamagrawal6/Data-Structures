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
    }

    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void midsplit(Node* head, Node** a, Node** b){
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = NULL; 
}

Node* combine(Node* a, Node* b){
    Node* sorted = NULL;

    if(a == NULL){
        return b;
    }
    else if(b == NULL){
        return a;
    }

    if(a->data < b->data){
        sorted = a;
        sorted->next = combine(a->next, b); 
    }

    else{
        sorted = b;
        sorted->next = combine(b->next, a); 
    }

    return sorted;
}

void mergesort(Node** headref){
    Node* a = NULL;
    Node* b = NULL;

    if(*headref == NULL || (*headref)->next == NULL){
        return;
    }

    midsplit(*headref, &a, &b);

    mergesort(&a);
    mergesort(&b);

    *headref = combine(a, b);
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
    
    mergesort(&head); //5->6->7->8->11->13->NULL
    cout<<"Sorted List: "<<endl;
    printlist(head);

    return 0;
}