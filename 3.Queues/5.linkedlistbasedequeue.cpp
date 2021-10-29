#include <bits/stdc++.h> 
using namespace std;

struct Node { 
	int data; 
	Node *prev, *next; 

	static Node* getnode(int data){ 
		Node* newNode = (Node*)malloc(sizeof(Node)); 
		newNode->data = data; 
		newNode->prev = newNode->next = NULL; 
		return newNode; 
	} 
}; 

class Deque { 
	Node* front; 
	Node* rear; 
	int Size; 

    public: 
	Deque(){ 
		front = rear = NULL; 
		Size = 0; 
	} 
	void insertFront(int data); 
	void insertRear(int data); 
	void deleteFront(); 
	void deleteRear(); 
	int getFront(); 
	int getRear(); 
	bool isEmpty(); 
}; 

void Deque::insertFront(int data){ 
    Node* temp = Node::getnode(data);
    if(front == NULL){
        front = temp;
        rear = front;
        return;
    }
    temp->next = front;
    front->prev = temp;
    front = temp;
} 

void Deque::insertRear(int data){ 
	Node* temp = Node::getnode(data);
    if(front == NULL){
        front = temp;
        rear = front;
        return;
    }
    temp->prev = rear;
    rear->next = temp;
    rear = temp;
}

void Deque::deleteFront() { 
	if(front == rear){
	    front = rear = NULL;
	    return;
	}
	front = front->next;
	front->prev = NULL;
} 

void Deque::deleteRear() { 
    if(front == rear){
	    front = rear = NULL;
	    return;
	}
	rear = rear->prev;
	rear->next = NULL;
} 

int Deque::getFront(){ 
	if(isEmpty()){
		return -1; 
    }
	return front->data; 
} 

int Deque::getRear(){  
	if(isEmpty()){
		return -1;
    } 
	return rear->data; 
}

bool Deque::isEmpty(){ 
	return (front == NULL); 
}

int main(){ 
    Deque dq;
    
    dq.insertFront(1);
    dq.insertFront(2);
    dq.insertFront(3);
    dq.insertFront(4);

    cout<<dq.getFront()<<" "<<dq.getRear()<<endl;

    dq.deleteRear();
    dq.deleteRear();
    dq.insertRear(4);
    dq.insertRear(3);
    dq.insertRear(2);
    dq.insertRear(1);

    while(!dq.isEmpty()){
        cout<<dq.getFront()<<" ";
        dq.deleteFront();
    }
    cout<<endl;

	return 0; 
} 