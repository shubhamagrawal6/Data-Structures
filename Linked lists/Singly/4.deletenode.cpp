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

//Function to delete node (since head is not changed headref is not required)
void deletenode(Node* head, int pos) {
    //Corner case
    if(head == NULL) {
        cout<<"Empty List :)";
    }
    //Checking position
    Node* temp1 = head;
    while((--pos - 1) && (temp1 != NULL))
    temp1 = temp1->next;
    //Corner case
    if(temp1 == NULL) {
        cout<<"Invalid Position \n";
    }
    //To delete
    else {
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
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
    printlist(head);
    //Deleting
    deletenode(head, 4); //7->13->11->5->NULL
    cout<<"After deleting \n";
    printlist(head);
    return 0;
}
