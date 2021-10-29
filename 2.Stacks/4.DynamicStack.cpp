#include <bits/stdc++.h>
using namespace std;

class dynamicStack{
    int top;
    void doubleStack();
    
    public:
    int capacity, *array;

    dynamicStack(){
        top = -1;
        capacity = 1;
        array = new int[capacity];
    }

    bool isFull();
    bool isEmpty();
    void push(int item);
    int pop();
    int peek();
};

void dynamicStack::doubleStack(){
    capacity *= 2;

    int* temp = new int[capacity];
    for (int i = 0; i < capacity/2; i++)
        temp[i] = array[i];
    delete array;

    array = new int[capacity];
    for (int i = 0; i < capacity/2; i++)
        array[i] = temp[i];
    delete temp;
}

bool dynamicStack::isFull(){
    return (top == capacity-1);
}

bool dynamicStack::isEmpty(){
    return (top == -1);
}

void dynamicStack::push(int item){
    if(this->isFull()){
        this->doubleStack();
    }

    array[++(this->top)] = item;
}

int dynamicStack::pop(){
    return array[(this->top)--];
}

int dynamicStack::peek (){
    return array[this->top];
}


int main(){
    dynamicStack stack;
    int option, val;

    do{
        cout<<"1.PUSH"<<endl;
        cout<<"2.POP"<<endl;
        cout<<"3.TOP"<<endl;
        cout<<"4.EXIT"<<endl;
        cin>>option;

        switch(option){
            case 1:
                cout<<"Enter the value to be pushed: ";
                cin>>val;
                stack.push(val);
                break;

            case 2:
                if (stack.isEmpty())
                    cout<<"Underflow"<<endl;
                else
                    cout<<stack.pop()<<" popped out of stack."<<endl;
                break;

            case 3:
                cout<<stack.peek()<<" is top element."<<endl;
                break;

            case 4:
                exit (0);

            default:
                cout<<"Invalid Option."<<endl;
        }
    }while (option != 4);

    return 0;
}