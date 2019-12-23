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

void deletenode(Node** nodeptrref) {
    //Corner case if given is last node of list
    if((*nodeptrref)->next == NULL) {
        *nodeptrref = NULL;
    }
    
    //Copy data from next node to this node and delete the next node ;)
    else {
        (*nodeptrref)->data = (*nodeptrref)->next->data;
        (*nodeptrref)->next = (*nodeptrref)->next->next;
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
    //Deleting node in between
    deletenode(&(head->next->next->next)); //7->13->11->5->NULL
    cout<<"After deleting \n";
    printlist(head);
    cout<<"End of test 1 \n";
    //Deleting node at end
    deletenode(&(head->next->next->next)); //7->13->11->NULL
    cout<<"After deleting \n";
    printlist(head);
    cout<<"End of test 2 \n";
    return 0;
}