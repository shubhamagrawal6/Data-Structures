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

void loopcheck(Node* head){
    int count = 0;
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            do{
                slow = slow->next;
                count++;
            } while(fast != slow); 
            cout<<"Loop exists with number of elements = "<<count<<endl;
            return;
        }
    }

    cout<<"Loop does not exist :) "<<endl;
}

void removeloop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            slow = head->next;
            while(slow != fast->next){
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
        }
    }
}

int main(){
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    //7->13->11->8->5->6->NULL
    printlist(head);
    
    loopcheck(head);
    cout<<"End of test 1 "<<endl;

    head->next->next->next->next->next->next = head->next->next;
    /* 
    7->13->11->8
           |  |
           6<-5 
    */
    cout<<"Loop created "<<endl;
 
    loopcheck(head);
    cout<<"End of test 2 "<<endl;

    removeloop(head);
    //7->13->11->8->5->6->NULL
    cout<<"Loop removed "<<endl;

    loopcheck(head);
    printlist(head);
    cout<<"End of test 3 "<<endl;

    return 0;
}