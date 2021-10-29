#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
    
    Node(int x){
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void displayList(Node *head){
    while(head->next){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data;
}

void append(Node** head_ref, int new_data){
    Node* new_node = new Node(new_data);
    Node* last = *head_ref; 
    new_node->next = NULL;
    if(*head_ref == NULL){
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    while(last->next != NULL){
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

Node* reverseDLL(Node* head){
    while(head->next){
        Node* temp = head->next;
        head->next = head->prev;
        head->prev = temp;
        head = temp;
    }
    head->next = head->prev;
    head->prev = NULL;
    return head;
}

int main() {
	Node* head = new Node(7);
    append(&head, 13);
    append(&head, 11);
    append(&head, 8);
    append(&head, 5);
    // 7->13->11->8->5->NULL
    displayList(head);

    head = reverseDLL(head);
    displayList(head); // 5->8->11->13->7->NULL
	return 0;
}