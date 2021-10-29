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

void deletenode(Node* head, int pos){
    if(!head){
        cout<<"Empty List :)"<<endl;
        return;
    }

    Node* temp1 = head;
    while((--pos - 1) && (temp1)){
        temp1 = temp1->next;
    }

    if(temp1 == NULL){
        cout<<"Invalid Position "<<endl;
        return;
    }
    
    else{
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
    }
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    //7->13->11->8->5->NULL
    printlist(head);

    deletenode(head, 4); //7->13->11->5->NULL
    cout<<"After deleting "<<endl;
    printlist(head);
    return 0;
}
