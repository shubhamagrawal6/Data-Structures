#include<bits/stdc++.h>
using namespace std;

//Structure of the node
struct Node {
    int data;
    Node* next;
    //Construction of each Node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

//Printing the list
void printlist(Node* head) {
    //Corner case
    if(head == NULL)
    cout<<"Empty List :) \n";
    
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next; 
    }
}

//Reverse function (head is changed so headref is required)
void reverse(Node** headref) {
    //Configuring temporary pointers
    Node* temp1 = *headref;
    Node* temp2 = (*headref)->next;
    Node* temp3 = (*headref)->next->next;

    //Since first node is now last its next is NULL
    temp1->next = NULL;

    //Reversing links upto the last node
    while(temp3 != NULL) {
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3->next;
    }
    
    //Joining the last node to rest of the list
    temp2->next = temp1;
    //Reassigning head
    *headref = temp2;
}

//Another logic for reverse function (Similar to concept of rotation, but from between)
void reverse2 (Node** headref) {
    Node* current = *headref;
    Node* subsequent;

    while(current->next != NULL) {
        subsequent = current->next;
        current->next = subsequent->next;
        subsequent->next = *headref;
        *headref = subsequent;
    }
}

//Main code
int main() {
    //Creating list
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    //7->13->11->8->5->NULL
    cout<<"Original list: \n";
    printlist(head);
    reverse(&head); //5->8->11->13->7->NULL
    cout<<"Reversed list: \n";
    printlist(head);
    cout<<"End of test 1 \n";
    reverse2(&head); //7->13->11->8->5->NULL
    cout<<"Reversed list: \n";
    printlist(head);
    cout<<"End of test 2 \n";

    return 0;
}