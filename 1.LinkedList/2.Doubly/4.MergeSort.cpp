#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next, *prev;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};

void displayList(Node* head){
    while(head->next){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<head->data<<endl;

    while(head->prev){
        cout<<head->data<<" ";
        head = head->prev;
    }
    cout<<head->data<<endl;
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

void swap(int *A, int *B){
	int temp = *A;
	*A = *B;
	*B = temp;
}

Node* merge(Node* head1, Node* head2){
    Node* ans = new Node(0);
    Node* curr = ans;
    while(head1 && head2){
        if(head1->data < head2->data){
            curr->next = head1;
            curr->next->prev = curr;
            curr = curr->next;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            curr->next->prev = curr;
            curr = curr->next;
            head2 = head2->next;
        }
    }
    if(head1){
        curr->next = head1;
        head1->prev = curr;
    }
    if(head2){
        curr->next = head2;
        head2->prev = curr;
    }
    if(ans->next){
        ans->next->prev = NULL;
    }
    return ans->next;
}

Node* sortDoubly(Node *head){
	if(!head || !(head->next)){
	    return head;
	}
	Node* fast = head;
	Node* slow = head;
	while(fast && fast->next){
	    fast = fast->next->next;
	    slow = slow->next;
	}
	slow->prev->next = NULL;
	slow->prev = NULL;
	fast = sortDoubly(slow);
	slow = sortDoubly(head);
	return merge(fast, slow);
}

int main(){
    Node* head = new Node(7);
    append(&head, 13);
    append(&head, 11);
    append(&head, 8);
    append(&head, 5);
    // 7->13->11->8->5->NULL
    displayList(head);

    head = sortDoubly(head);
    // 5->7->8->11->13->NULL
    displayList(head);
	return 0;
}