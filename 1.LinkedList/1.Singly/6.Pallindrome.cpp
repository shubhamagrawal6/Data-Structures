#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node* head){
    if(!head){
        cout<<"Empty List :) "<<endl;
    }

    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void push(Node** headref, char data){
    Node* newnode = new Node(data);
    newnode->next = *headref;
    *headref = newnode;
}

bool checkpall(Node** leftref, Node* right){
    if(!right){
        return true;
    }

    if(checkpall(leftref, right->next) && (*leftref)->data == right->data){
        (*leftref) = (*leftref)->next;
        return true;
    }
    
    return false;
}

void drivercheckpall(Node* head){
    Node* left = head;
    Node* right = head;

    if(checkpall(&left,right)){
        cout<<"The list is a pallindrome "<<endl;
        return;
    }

    cout<<"The list is not a pallindrome "<<endl;
}

int main(){
    Node* head = NULL;
    char str1[] = "racecar"; //Pallindrome of odd number
    char str2[] = "2332"; //Pallindrome of even number
    char str3[] = "pallindrome"; //Not pallindrome ;)

    for(int i=0; str1[i] != '\0'; i++){
        push(&head, str1[i]);
    }

    drivercheckpall(head);
    cout<<"End of test 1 "<<endl;

    head = NULL;
    for(int i=0; str2[i] != '\0'; i++){
        push(&head, str2[i]);
    }

    drivercheckpall(head);
    cout<<" End of test 2 "<<endl;

    head = NULL;
    for(int i=0; str3[i] != '\0'; i++){
        push(&head, str3[i]);
    }

    drivercheckpall(head);
    cout<<" End of test 3 "<<endl;

    return 0;
}