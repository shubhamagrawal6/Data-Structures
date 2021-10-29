#include <bits/stdc++.h>
using namespace std;

struct StackNode{
    int data;
    StackNode *next;

    StackNode(int a){
        data = a;
        next = NULL;
    }
};

class MyStack{
    StackNode *top;

    public:
    MyStack(){
        top = NULL;
    }
    void push(int);
    int pop();
};

void MyStack::push(int x){
    StackNode* temp = new StackNode(x);
    temp->next = top;
    top = temp;
}

int MyStack::pop(){
    if(top == NULL){
        return -1;
    }
    int temp = top->data;
    top = top->next;
    return temp;
}

int main() {
    
}