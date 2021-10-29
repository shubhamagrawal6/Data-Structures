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
    MyStack ms;
    ms.push(5); // 5
    ms.push(8); // 8 5
    ms.push(7); // 7 8 5
    cout<<ms.pop()<<endl; // 8 5
    ms.push(6); // 6 8 5
    ms.push(3); // 3 6 8 5
    cout<<ms.pop()<<endl; // 6 8 5
    cout<<ms.pop()<<endl; // 8 5
    cout<<ms.pop()<<endl; // 5

    return 0;
}