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

//To insert node at beginning of list (in these codes head maybe changed so headref is required)
void insbegin(Node** headref, int data) {
    //Creating new node
    Node* newnode = new Node(data);
    //Connecting it to the start
    newnode->next = *headref;
    //Changing head
    *headref = newnode;
}

//To insert node at end of list
void insend(Node** headref, int data) {
        //Creating new node
        Node* newnode = new Node(data);
        //Corner case
        if(*headref == NULL)
        *headref = newnode;

        else {
            //Finding the last node of list
            Node* last = *headref;
            while(last->next != NULL) {
                last = last->next; 
            }
            //Attaching the node
            last->next = newnode;
        }
}

//To insert node after certain element
void insafter(Node** prevnoderef, int data) {
    //Corner case:- If given list is empty
    if(*prevnoderef == NULL)
    cout<<"The given list is empty :) \n";

    else {
        //Creating new node
        Node* newnode = new Node(data);
        //Attaching the new node
        newnode->next = (*prevnoderef)->next;
        (*prevnoderef)->next = newnode;
    }
}

//Main code
int main () {
    Node* head = NULL;

    insafter(&head, 9); //Corner case
    printlist(head);
    cout<<"End of test 0 \n";
    insend(&head, 9); //Corner case:- 9->NULL
    printlist(head);
    cout<<"End of test 1 \n";
    insbegin(&head, 13); //13->9->NULL
    printlist(head);
    cout<<"End of test 2 \n";
    insbegin(&head, 11); //11->13->9->NULL
    printlist(head);
    cout<<"End of test 3 \n";
    insend(&head, 19); //11->13->9->19->NULL
    printlist(head);
    cout<<"End of test 4 \n";
    insafter(&head->next->next, 17); //11->13->9->17->19->NULL
    printlist(head);
    cout<<"End of test 5 \n";

    return 0;
}