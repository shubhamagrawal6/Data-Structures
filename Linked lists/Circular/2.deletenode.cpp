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

Node* insertempty(Node *last, int data) {
    if(last != NULL) {
        return last;
    }

    Node *temp = new Node(data);
    
    last = temp;
    last->next = last; //Self loop

    return last;
}

Node* insertbegin(Node* last, int data) {
    if(last == NULL) {
        return insertempty(last, data);
    }

    Node* temp = new Node(data);
    
    temp->next = last->next;
    last->next = temp;
    
    return last;
}

void deletenode(Node **headref, int item) {
    //If list is empty
    if(*headref == NULL){
        cout<<"Empty List \n";
        return;
    }
    
    //If node to be deleted is at head
    if((*headref)->data == item){
        //If list is a self loop
        if((*headref)->next == (*headref)){
            delete *headref;
            *headref = NULL;
        }

        else{
            Node *temp  = (*headref)->next;
            while(temp->next != *headref){
                temp = temp->next;
            }
            temp->next = (*headref)->next;
            *headref = temp->next;
        }
    }
    
    //If node to be deleted is anywhere except head
    Node *temp  = *headref;
    while(temp != *headref){
        if(temp->next->data == item){
            temp->next = temp->next->next;
            break;
        }
        else{
            temp = temp->next;
        }
    }
}

int main(){
    Node *itr = new Node(23);
    printlist(itr);
    cout<<"test\n";
    
    deletenode(&itr,23);
    printlist(itr);
    cout<<"test\n";

    itr = insertbegin(itr, 4);
    itr = insertbegin(itr, 12);
    itr = insertbegin(itr, 8);
    itr = insertbegin(itr, 1);
    itr = insertbegin(itr, 9);
    itr = insertbegin(itr, 37);
    printlist(itr);
    cout<<"test\n";

    deletenode(&itr, 12);
    printlist(itr);
    cout<<"test\n";
    
    deletenode(&itr, 37);
    printlist(itr);
    cout<<"test\n";
}