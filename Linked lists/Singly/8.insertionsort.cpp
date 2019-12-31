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

//Inserting a single node in sorted linked list (headref used as head may change)
//Sort type: Ascending
void sortinsert (Node** headref, Node* newnode) {
    //Corner case
    if (*headref == NULL || (*headref)->data >= newnode->data) {
        newnode->next = *headref;
        *headref = newnode;
    }

    else {
        Node* current;
        current = *headref;
        while (current->next != NULL && current->next->data < newnode->data)
            current = current->next;
        newnode->next = current->next;
        current->next = newnode;
    }
}

//Creating sorted list (headref used as head changes)
void insertionsort (Node** headref) {
    //Pointer to be used as head for sorted linked list
    Node* sorted = NULL;
    //Traverse the given linked list and insert every node in sorted list
    Node* current = *headref;

    while (current != NULL) {
        Node* next = current->next;
        sortinsert(&sorted, current);
        current = next;
    }
    *headref = sorted;
}

//Main code
int main() {
    //Creating list
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    //7->13->11->8->5->6->NULL
    printlist(head);

    //Sorting the list
    insertionsort(&head); //5->6->7->8->11->13->NULL
    cout<<"Sorted List: \n";
    printlist(head);

    return 0;
}