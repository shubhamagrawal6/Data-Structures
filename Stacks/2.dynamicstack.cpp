//Dynamic implementation of stack

#include <bits/stdc++.h>
using namespace std;

class dynamicStack {
    private:
        int top;
        void doubleStack();
    public:
        int capacity, *array;

    dynamicStack() {
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

void dynamicStack :: doubleStack() {
    // Doubling the capacity
    capacity *= 2;

    // Copying available data into temporary array
    // and then deleting the original array
    int* temp = new int[capacity];
    for (int i = 0; i < capacity/2; i++)
        temp[i] = array[i];
    delete array;

    // Allocating new memory to original again
    // which is double the size as of previous one
    // and deleting the temporary array after copying
    // the elements into newly allocated array
    array = new int[capacity];
    for (int i = 0; i < capacity/2; i++)
        array[i] = temp[i];
    delete temp;
}

bool dynamicStack :: isFull() {
    return (top == capacity-1);
}

bool dynamicStack :: isEmpty() {
    return (top == -1);
}

void dynamicStack :: push(int item) {
    if (this->isFull())
        this->doubleStack();

    array[++(this->top)] = item;
}

int dynamicStack :: pop() {
    return array[(this->top)--];
}

int dynamicStack :: peek () {
    return array[this->top];
}


int main() {
    dynamicStack stack;
    int option, val;

    do {
        cout << "\n1.PUSH\n2.POP\n3.TOP\n4.EXIT\n";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Enter the value to be pushed: ";
                cin >> val;
                stack.push(val);
                break;

            case 2:
                if (stack.isEmpty())
                    cout << "Underflow\n";
                else
                    cout << stack.pop() << " popped out of stack.\n";
                break;

            case 3:
                cout << stack.peek() << " is top element.\n";
                break;

            case 4:
                exit (0);

            default:
                cout << "Invalid Option.\n";
        }
    }
    while (option != 4);

    return 0;
}