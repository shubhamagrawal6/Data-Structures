#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int top, max, *arr;

    Stack(){
        top = -1;
    }

    void size(int x){
        max = x;
        arr = new int[x];
    }

    bool checkempty(){
        return (top == -1);
    }

    bool checkfull(){
        return (top == max-1);
    }

    void push(int item){
        arr[++(this->top)] = item;
    }

    int pop(){
        return arr[(this->top)--];
    }

    int peek(){
        return arr[this->top];
    }
};

int main(){
    Stack stk;
    int max, opt, val;

    cout<<"Enter maximum size: ";
    cin>>max;

    stk.size(max);

    while(true){
        cout<<"1.Push element "<<endl;
        cout<<"2.Pop element "<<endl;
        cout<<"3.View top element "<<endl;
        cout<<"Any other key to Quit "<<endl;
        cin>>opt;

        switch(opt){
            case 1:
                if (stk.checkfull()){
                    cout<<"Stack is full"<<endl;
                }
                else{
                    cout<<"Enter the value to be pushed: ";
                    cin>>val;
                    stk.push(val);
                }
                break;
            
            case 2:
                if (stk.checkempty()){
                    cout<<"Stack is empty"<<endl;
                }
                else
                    cout<<stk.pop()<<" is popped out of the stack."<<endl;
                break;
            
            case 3:
                cout<<stk.peek()<<" is the top element."<<endl;
                break;
            
            default:
                exit(0);
                break;
        }
    }

    return 0;
}