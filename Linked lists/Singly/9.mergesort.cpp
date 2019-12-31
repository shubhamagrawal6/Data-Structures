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

//Function to split the given list from centre
//Reference to the sublists is given since their value is to be changed
void midsplit(Node* head, Node** a, Node** b) {
    Node* slow = head;
    Node* fast = head->next;

    //When fast is at last element or NULL the slow pointer will be at the centre
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    //Assigning the heads to the respective sublists
    *a = head; //1st half
    *b = slow->next; //2nd half
    //Splitting the list from centre
    slow->next = NULL; 
}

//Function to combine the splitted lists while also sorting them, it returns the combined list
//Sort type: Ascending
Node* combine(Node* a, Node* b) {
    Node* sorted = NULL;

    //Terminating conditions
    if(a == NULL) return b;
    else if(b == NULL) return a;

    //Sorting
    if(a->data < b->data) {
        sorted = a;
        sorted->next = combine(a->next, b); 
    }

    else {
        sorted = b;
        sorted->next = combine(b->next, a); 
    }

    //Returning pointer to sorted list
    return sorted;
}

//Merge sort function (headref given because head is changed)
void mergesort(Node** headref) {
    Node* a = NULL;
    Node* b = NULL;

    //Terminating condition
    if(*headref == NULL || (*headref)->next == NULL) return;

    //Splitting the list
    midsplit(*headref, &a, &b);

    //Recursive call on splitted lists
    mergesort(&a);
    mergesort(&b);

    //Combining the splitted and sorted lists and assigning head
    *headref = combine(a, b);
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
    //Sorting
    mergesort(&head); //5->6->7->8->11->13->NULL
    cout<<"Sorted List: \n";
    printlist(head);

    return 0;
}