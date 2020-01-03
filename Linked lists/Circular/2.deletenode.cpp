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

void printlist(Node *last) {
    
    if(last == NULL){
        cout<<"Empty List \n";
        return;
    }

    Node *temp;
    temp = last->next; 
    //Since it is circular linked list the next element will only be null if list is empty

    do {
        cout<<temp->data<<endl;
        temp = temp->next;
    }while(temp != last->next);

}