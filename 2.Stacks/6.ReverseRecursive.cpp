#include <bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
    if(s.empty()){
        return;
    }

    int x = s.top();
    s.pop();
    printStack(s);
    cout<<x<<" ";
    s.push(x);
}

void insertAtBottom(stack<int> &s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    
    int x = s.top();
    s.pop();
    insertAtBottom(s, element);
    s.push(x);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    
    int temp = s.top();
    s.pop();
    reverse(s);
    insertAtBottom(s, temp);
}


int main(){
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout<<"Original Stack:\n";
    printStack(st);
    cout<<endl;

    reverse(st);

    cout<<"Reversed Stack:\n";
    printStack(st);
    cout<<endl;

    return 0;
}