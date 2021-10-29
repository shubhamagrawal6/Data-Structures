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

void deletenode(Node** nodeptrref){
    if((*nodeptrref)->next == NULL){
        *nodeptrref = NULL;
        return;
    }

    (*nodeptrref)->data = (*nodeptrref)->next->data;
    (*nodeptrref)->next = (*nodeptrref)->next->next;
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    //7->13->11->8->5->NULL
    printlist(head);

    deletenode(&(head->next->next->next)); //7->13->11->5->NULL
    cout<<"After deleting \n";
    printlist(head);
    cout<<"End of test 1 \n";

    deletenode(&(head->next->next->next)); //7->13->11->NULL
    cout<<"After deleting \n";
    printlist(head);
    cout<<"End of test 2 \n";
    return 0;
}