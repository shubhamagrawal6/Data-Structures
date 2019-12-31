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
void printno(Node* head) {
    //Corner case
    if(head == NULL)
    cout<<"Empty List :) \n";

    while (head != NULL) {
        cout << head->data;
        head = head->next; 
    }
    cout<<endl;
}

//Push function for creating linked list
void push (Node** headref, int data) {
    Node* newnode = new Node(data);
    newnode->next = *headref;
    *headref = newnode;
}

//Reverse function for LL
void reverse(Node** headref) {
    Node* current = *headref;
    Node* subsequent;

    while(current->next != NULL) {
        subsequent = current->next;
        current->next = subsequent->next;
        subsequent->next = *headref;
        *headref = subsequent;
    }
}

//Reversing the lists is allowed
Node* add1(Node* head1, Node* head2) {
    Node* sum = NULL;

    //Reversing the numbers
    reverse(&head1);
    reverse(&head2);
    
    //Variable for carry
    int c = 0;

    //Carry variable is in condition because the number of digits may increase
    while(head1 || head2 || c) {
        int d = 0, a = 0, b = 0;
        
        if(head1) {
            a = head1->data;
            head1 = head1->next;
        }

        if(head2) {
            b = head2->data;
            head2 = head2->next;
        }

        d = a + b + c;

        //Generating carry
        if(d >= 10) {
            d = d%10;
            push(&sum, d);
            c = 1;
        }

        else {
            push(&sum, d);
            c = 0;
        } 
    }
    return sum;
}

//Main code
int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;

    //Creating 1st number in LL (421)
    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 4);
    cout<<"1st Number = ";
    printno(head1);

    //Creating 2nd number in LL (969)
    push(&head2, 9);
    push(&head2, 6);
    push(&head2, 9);
    cout<<"2nd Number = ";
    printno(head2);

    //To reverse lists and add
    cout<<"Sum of the Numbers is = ";
    printno(add1(head1, head2));
    cout<<"End of test 1 \n";

    return 0;
}