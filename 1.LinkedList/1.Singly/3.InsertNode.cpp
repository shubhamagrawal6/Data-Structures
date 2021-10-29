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

void insbegin(Node** headref, int data){
    Node* newnode = new Node(data);
    newnode->next = *headref;
    *headref = newnode;
}

void insend(Node** headref, int data){
        Node* newnode = new Node(data);
        if(*headref == NULL){
            *headref = newnode;
        }

        else{
            Node* last = *headref;
            while(last->next){
                last = last->next; 
            }
            last->next = newnode;
        }
}

void insafter(Node** prevnoderef, int data){
    if(*prevnoderef == NULL){
        cout<<"The given list is empty :) "<<endl;
    }

    else{
        Node* newnode = new Node(data);
        newnode->next = (*prevnoderef)->next;
        (*prevnoderef)->next = newnode;
    }
}

int main (){
    Node* head = NULL;

    insafter(&head, 9); //Corner case
    printlist(head);
    cout<<"End of test 0 "<<endl;
    insend(&head, 9); //Corner case:- 9->NULL
    printlist(head);
    cout<<"End of test 1 "<<endl;
    insbegin(&head, 13); //13->9->NULL
    printlist(head);
    cout<<"End of test 2 "<<endl;
    insbegin(&head, 11); //11->13->9->NULL
    printlist(head);
    cout<<"End of test 3 "<<endl;
    insend(&head, 19); //11->13->9->19->NULL
    printlist(head);
    cout<<"End of test 4 "<<endl;
    insafter(&head->next->next, 17); //11->13->9->17->19->NULL
    printlist(head);
    cout<<"End of test 5 "<<endl;

    return 0;
}