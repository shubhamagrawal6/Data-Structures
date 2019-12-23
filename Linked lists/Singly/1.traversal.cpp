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

//Printing list in reverse
void printreverse (Node* head) {
    //Terminating condition
    if (head == NULL) return;
    //Recurse for the remaining list
    printreverse(head->next);
    //Print data from last node
    cout << head->data << endl;
}

//Length of the list
int length(Node* head) {
    int count = 0;
    while (head != NULL) {
        head = head->next;
        count++;
    }
    return count;
}

// Main code
int main() {
    //Creating list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next= new Node(3);

    //Printing list
    printlist(head);
    cout<<"End of test 1 \n";

    //Printing in reverse
    printreverse(head);
    cout<<"End of test 2 \n";

    //Length of list
    cout<<"Length of linked list = "<<length(head)<<endl;
    cout<<"End of test 3 \n";

    return 0;
}