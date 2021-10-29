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

void printlist(Node* head) {
    if(!head){
        cout<<"Empty List :)"<<endl;
    }
    
    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void reverse(Node** headref) {
    Node* temp1 = *headref;
    Node* temp2 = (*headref)->next;
    Node* temp3 = (*headref)->next->next;

    temp1->next = NULL;

    while(temp3){
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }
    
    temp2->next = temp1;
    *headref = temp2;
}

void reverse2(Node** headref){
    Node* current = *headref;
    Node* subsequent;

    while(current->next){
        subsequent = current->next;
        current->next = subsequent->next;
        subsequent->next = *headref;
        *headref = subsequent;
    }
}

int main() {
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    
    //7->13->11->8->5->NULL
    cout<<"Original list: "<<endl;
    printlist(head);
    reverse(&head); //5->8->11->13->7->NULL
    cout<<"Reversed list: "<<endl;
    printlist(head);
    cout<<"End of test 1 "<<endl;
    reverse2(&head); //7->13->11->8->5->NULL
    cout<<"Reversed list: "<<endl;
    printlist(head);
    cout<<"End of test 2 "<<endl;

    return 0;
}