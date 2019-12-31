#include<bits/stdc++.h>
using namespace std;

//Structure of the node
struct Node {
    char data;
    Node* next;
    //Construction of each Node
    Node(char data) {
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

//Push function for creating linked list
void push (Node** headref, char data) {
    Node* newnode = new Node(data);
    newnode->next = *headref;
    *headref = newnode;
}

//Function to check pallindrome
bool checkpall(Node** leftref, Node* right) {
    //Terminating condition
    if (right == NULL) return true;

    /*Taking right to last and then coming back, also incrementing left each time we come back
      and checking the data */
    if(checkpall(leftref, right->next) && (*leftref)->data == right->data) {
        (*leftref) = (*leftref)->next;
        return true;
    }
    return false;
}

//Driver of function to check pallindrome
void drivercheckpall(Node* head) {
    Node* left = head;
    Node* right = head;

    if(checkpall(&left,right)) {
        cout<<"The list is a pallindrome \n";
    }

    else {
        cout<<"The list is not a pallindrome \n";
    }
}

//Main code
int main() {
    Node* head = NULL;
    char str1[] = "racecar"; //Pallindrome of odd number
    char str2[] = "2332"; //Pallindrome of even number
    char str3[] = "pallindrome"; //Not pallindrome ;)

    for(int i=0; str1[i] != '\0'; i++) push(&head, str1[i]);

    drivercheckpall(head);
    cout<< " End of test 1 \n";

    head = NULL;
    for(int i=0; str2[i] != '\0'; i++) push(&head, str2[i]);

    drivercheckpall(head);
    cout<< " End of test 2 \n";

    head = NULL;
    for(int i=0; str3[i] != '\0'; i++) push(&head, str3[i]);

    drivercheckpall(head);
    cout<< " End of test 3 \n";

    return 0;
}