//Array based implementation here, STL has Stacks with Dequeue

#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
        int top, max, *arr;

        Stack() {
            top = -1;
        }

        //Defines size of stk also creates new array everytime it is called
        void size(int x) {
            max = x;
            arr = new int[x];
        }

        bool checkempty() {
            return (top == -1);
        }

        bool checkfull () {
            return (top == max-1);
        }

        void push (int item) {
            //Increases the top variable from -1 to 0 and adds item to index 0 of the array
            arr[++(this->top)] = item;
        }

        int pop() {
            //Returns the top value & decreases the top variable so that part of array cannot be accessed
            return arr[(this->top)--];
        }

        int peek () {
            //Only returns value at top
            return arr[this->top];
        }
};

int main() {
    Stack stk;
    int max, opt, val;

    cout << "Enter maximum size: ";
    cin >> max;

    stk.size(max);

    while(true) {
        cout << "\n1.Push element\n2.Pop element\n3.View top element\nAny other key to Quit";
        cin >> opt;

        switch(opt) {
            case 1:
                if (stk.checkfull()) {
                    cout << "Stack is full\n";
                }
                else {
                    cout << "Enter the value to be pushed: ";
                    cin >> val;
                    stk.push(val);
                }
                break;
            
            case 2:
                if (stk.checkempty()) {
                    cout << "Stack is empty\n";
                }
                else
                    cout << stk.pop() << " is popped out of the stack.\n";
                break;
            
            case 3:
                cout << stk.peek() << " is the top element.\n";
                break;
            
            default:
                break;
        }
    }

    return 0;
}