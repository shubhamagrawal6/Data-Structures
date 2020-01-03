//We access circular linked lists by pointer to last element

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

Node* insertend(Node* last, int data) {
    if(last == NULL) {
        return insertempty(last, data);
    }

    Node* temp = new Node(data);

    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

Node* insertafter(Node* last, int data, int item) {
    if(last == NULL) {
        cout<<"Item not in list \n";
        return last;
    }

    Node *temp = new Node(data);
    Node *p = last->next;

    do {
        if(p->data == item) {
            temp->next = p->next;
            p->next = temp;

            if(p == last){
                last = temp;
            }
            return last;
        }
        p = p->next;
    }while(p != last->next);
    
    cout<<"Item not in list \n";
    return last;
}

int main() {
    Node* itr = NULL;
    
    itr = insertempty(itr, 5);
    printlist(itr);
    cout<<"test\n";
    itr = insertbegin(itr, 2);
    printlist(itr);
    cout<<"test\n";
    itr = insertend(itr, 7);
    printlist(itr);
    cout<<"test\n";
    itr = insertafter(itr, 3, 2);
    printlist(itr);
    cout<<"test\n";

    return 0;
}