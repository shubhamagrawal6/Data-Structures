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

void printno(Node* head){
    if(!head){
        cout<<"Empty List :) "<<endl;
    }

    while(head){
        cout<<head->data<<endl;
        head = head->next; 
    }
}

void push(Node** headref, int data){
    Node* newnode = new Node(data);
    newnode->next = *headref;
    *headref = newnode;
}

void reverse(Node** headref){
    Node* current = *headref;
    Node* subsequent;

    while(current->next){
        subsequent = current->next;
        current->next = subsequent->next;
        subsequent->next = *headref;
        *headref = subsequent;
    }
}

Node* add1(Node* head1, Node* head2){
    Node* sum = NULL;

    reverse(&head1);
    reverse(&head2);
    
    int c = 0;

    while(head1 || head2 || c){
        int d = 0, a = 0, b = 0;
        
        if(head1){
            a = head1->data;
            head1 = head1->next;
        }

        if(head2){
            b = head2->data;
            head2 = head2->next;
        }

        d = a + b + c;

        if(d >= 10){
            d = d%10;
            push(&sum, d);
            c = 1;
        }

        else{
            push(&sum, d);
            c = 0;
        } 
    }

    return sum;
}

int main(){
    Node* head1 = NULL;
    Node* head2 = NULL;

    push(&head1, 1);
    push(&head1, 2);
    push(&head1, 4);
    cout<<"1st Number = ";
    printno(head1);

    push(&head2, 9);
    push(&head2, 6);
    push(&head2, 9);
    cout<<"2nd Number = ";
    printno(head2);

    cout<<"Sum of the Numbers is = ";
    printno(add1(head1, head2));
    cout<<"End of test 1 "<<endl;

    return 0;
}