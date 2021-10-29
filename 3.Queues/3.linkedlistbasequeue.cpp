#include<bits/stdc++.h>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;
    
    QueueNode(int a){
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    
    MyQueue() {
        front = rear = NULL;
    }
    void push(int);
    int pop();
};

void MyQueue::push(int x){
    if(rear == NULL){
        rear = new QueueNode(x);
        front = rear;
        return;
    }
    rear->next = new QueueNode(x);
    rear = rear->next;
}

int MyQueue::pop(){
    if(front == NULL){
        return -1;
    }
    int temp = front->data;
    if(front == rear){
        front = rear = NULL;
        return temp;
    }
    front = front->next;
    return temp;
}

int main(){
    MyQueue *q = new MyQueue();
    q->push(1);
    q->push(2);
    q->push(3);

    cout<<q->front->data<<endl;
    q->pop();
    q->pop();
    cout<<q->front->data<<endl;

    return 0;
}

