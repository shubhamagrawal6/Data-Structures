#include <bits/stdc++.h>
using namespace std;

class Queue {
    stack <int> s1, s2;

    public:
    void enqueue(int);
    void dequeue();
    int front();
};

void Queue::enqueue(int x){
    while (!s1.empty()) {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(x);
    while (!s2.empty()) {
        s1.push(s2.top());
        s2.pop();
    }
}

void Queue::dequeue(){
    if (s1.empty()) {
        cout<<"Queue is empty."<<endl;
        return;
    }
    s1.pop();
}

int Queue::front(){
    return s1.top();
}


int main(){
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout<<q.front()<<endl;
    q.dequeue();
    q.dequeue();
    cout<<q.front()<<endl;
    
    return 0;
}