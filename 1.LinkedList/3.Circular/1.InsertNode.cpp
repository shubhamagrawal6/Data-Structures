#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printlist(Node *last){
    if(!last){
        cout<<"Empty List "<<endl;
        return;
    }

    Node *temp;
    temp = last->next; 

    do{
        cout<<temp->data<<endl;
        temp = temp->next;
    }while(temp != last->next);
}

Node* insertbegin(Node* last, int data){
    Node* temp = new Node(data);
    if(!last){
        return temp;
    }

    temp->next = last->next;
    last->next = temp;
    
    return last;
}

Node* insertend(Node* last, int data){
    Node* temp = new Node(data);
    if(!last){
        return temp;
    }

    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

Node* insertafter(Node* last, int data, int item){
    if(!last){
        cout<<"Item not in list "<<endl;
        return last;
    }

    Node *temp = new Node(data);
    Node *p = last->next;

    do{
        if(p->data == item){
            temp->next = p->next;
            p->next = temp;

            if(p == last){
                last = temp;
            }
            return last;
        }
        p = p->next;
    }while(p != last->next);
    
    cout<<"Item not in list "<<endl;
    return last;
}

int main(){
    Node* itr = new Node(5);
    printlist(itr);
    
    cout<<"test"<<endl;
    itr = insertbegin(itr, 2);
    printlist(itr);
    
    cout<<"test"<<endl;
    itr = insertend(itr, 7);
    printlist(itr);
    
    cout<<"test"<<endl;
    itr = insertafter(itr, 3, 2);
    printlist(itr);

    return 0;
}