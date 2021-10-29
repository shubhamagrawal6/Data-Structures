#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node* head) {
    if(!head){
        cout<<"Empty List :)"<<endl;
        return;
    }
    
    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void printreverse(Node* head){
    if(!head){
        return;
    }
    
    printreverse(head->next);
    cout<<head->data<<endl;
}

int length(Node* head){
    int count = 0;
    while(head){
        head = head->next;
        count++;
    }
    return count;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next= new Node(3);

    printlist(head);
    cout<<"End of test 1"<<endl;

    printreverse(head);
    cout<<"End of test 2"<<endl;

    cout<<"Length of linked list = "<<length(head)<<endl;
    cout<<"End of test 3"<<endl;

    return 0;
}