//Reversing a stack using iterative method

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node (int data) {
            this->data = data;
            this->next = NULL;
        }
};

class Stack {
    Node* top;
    public:
        void push(int data);
        Node* pop();
        void display();
        void reverse();
};

void Stack::push(int data) {
    if (top == NULL) {
        top = new Node (data);
        return;
    }
    Node* t = new Node(data);
    t->next = top;
    top = t;
}

Node* Stack :: pop() {
    Node* s = top;
    top = top->next;
    return s;
}

void Stack :: display() {
    Node* curr = top;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

void Stack:: reverse() {
    Node *prev, *cur, *succ;
    cur = prev = top;
    cur = cur->next;
    prev->next = NULL;
    while (cur != NULL) {

        succ = cur->next;
        cur->next = prev;
        prev = cur;
        cur = succ;
    }
    top = prev;
}


int main() {
    Stack *s = new Stack();
    s->push(1);
    s->push(2);
    s->push(3);
    s->push(4);

    cout << "Original Stack:\n";
    s->display();

    s->reverse();

    cout << "Reversed Stack:\n";
    s->display();

    return 0;
}