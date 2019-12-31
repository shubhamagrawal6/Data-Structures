/*
Explaination for Removal of Loop:

Based on 'Tortoise and Hare Technique'
                                                    (Meeting point)
                                          --- (k nodes) --- * ---------
                                        /                               \
    * --------- (m nodes) ----------- *                                  |
 (start)           (beginning of loop)  \                               /
                                          ------ (n nodes in loop) ----
    Explanation:
        Let m = number of nodes before the loop has begun,
            k = number of nodes from beginning point where fast and slow will meet
            n = total length of the loop
        Now,  Distance travelled by fast = 2*Distance travelled by slow
        Hence,  m + n*x + k = 2*(m + n*y + k)   where
            x = number of cycles completed by fast pointer before first meet
            y = number of cycles completed by slow pointer before first meet
        
        Solving, m + k = (x - 2y)*n
        This shows, (m + k) is multiple of n. So once they meet, if the slow
        starts from head and fast starts from k with SAME PACE now, they will 
        meet at the beginning of loop. This is because, 'slow' has covered m steps
        and has reached at the beginning of loop, 'fast' has also covered m steps
        and has already started k steps in advance (covering m+k steps in total).
        Since m+k is multiple of n, 'fast' has to be at the start of loop.
        Now once we are at start of loop, we get the pointer of the last node and 
        its next as NULL.

*/

#include<bits/stdc++.h>
using namespace std;

//Structure of the node
struct Node {
    int data;
    Node* next;
    //Construction of each Node
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

//Printing the list
void printlist(Node* head) {
    //Corner case
    if(head == NULL)
    cout<<"Empty List :) \n";
    
    while (head != NULL) {
        cout << head->data << endl;
        head = head->next; 
    }
}

//Function to find existence and length of loop
void loopcheck(Node* head) {
    int count = 0;
    Node* slow = head;
    Node* fast = head;

    //In while condition we check both fast and fast->next beacuse fast increments twice in each step
    //No need to check slow in while condition as it is covered under fast and fast->next
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            //We use do while loop since slow and fast are initially the same
            do {
                slow = slow->next;
                count++;
            } while(fast != slow); 
            cout<<"Loop exists with number of elements = "<<count<<endl;
            return;
        }
    }
    cout<<"Loop does not exist :) \n";
}

//To remove the loop
void removeloop(Node* head) {
    Node* slow = head;
    Node* fast = head;

    //In while condition we check both fast and fast->next beacuse fast increments twice in each step
    //No need to check slow in while condition as it is covered under fast and fast->next
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) {
            /*slow is assigned the 2nd element so that it can coincide with fast->next
            and hence we get fast at the end of loop and not its beginning*/
            slow = head->next;
            while(slow != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
            //Opening the loop from the last element
            fast->next = NULL;
        }
    }
}

//Main code
int main() {
    //Creating list
    Node* head = new Node(7);
    head->next = new Node(13);
    head->next->next = new Node(11);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    //7->13->11->8->5->6->NULL
    printlist(head);
    loopcheck(head);
    cout<<"End of test 1 \n";
    //Loop creation
    head->next->next->next->next->next->next = head->next->next;
    /* 
    7->13->11->8
           |  |
           6<-5 
    */
    cout<<"Loop created \n";
    loopcheck(head);
    cout<<"End of test 2 \n";
    //Removing loop
    removeloop(head);
    //7->13->11->8->5->6->NULL
    cout<<"Loop removed \n";
    loopcheck(head);
    printlist(head);
    cout<<"End of test 3 \n";

    return 0;
}