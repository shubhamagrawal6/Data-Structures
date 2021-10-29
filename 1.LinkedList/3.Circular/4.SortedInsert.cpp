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

void sortedinsert(Node **headref, Node *newnode){
    Node* temp = *headref;
    if(*headref == NULL){
        *headref = newnode;
        (*headref)->next = *headref;
    }
    
    else if((*headref)->data >= newnode->data){
        while(temp->next != *headref){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = *headref;
        *headref = newnode;
    }

    else{
        temp = *headref;
        while(temp->next != *headref && temp->next->data < newnode->data){
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

int main(){
    int arr[] ={19, 34, 2, 21, 0, 79};
    Node *head = NULL, *newnode;  

    // 0->2->19->21->34->79
    for(int i=0; i<6; i++){  
        newnode = new Node(arr[i]); 
        sortedinsert(&head, newnode);  
    }
    
    printlist(head);   
    return 0;
}