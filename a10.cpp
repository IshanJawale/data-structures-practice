/*
Simulation of pizza parlor: Pizza parlor accepting maximum M orders. Orders are served on a first come first served basis. Order once placed cannot be canceled. Write C++ program to simulate the system using simple queue or circular queue
*/

#include<iostream>
using namespace std;



class Queue{
    public:
    const int M = 5;
    int front, rear, i;
    int queue[5];
    Queue() {
        front = -1;
        rear = -1;
        i = 0;
    }
    void pop() {
        front++;
        queue[front] = 0;
    }
    void push() {
        rear++;
        queue[rear] = i;
        i++;
    }
    bool isfull() {
        if(rear == 5) 
            return true;
        return false;
    }
    bool isempty(){
        if(front == rear)
            return true;
        return false;
    }
    
};

int main() {
    Queue q;
    int ch;
    do {
    cout << "Enter:\n1. New Customer\n2. Order served\n0. Exit\nYourChoice: ";
    cin >> ch;
        switch(ch) {
            case 1: {
                if(!q.isfull()) {
                    q.push();
                    cout << "New Customer in line..." << endl;
                    cout << q.i << endl;
                }
                else {
                    cout << "The queue is full..." << endl;
                }
                break;
            }
            case 2: {
                if(!q.isempty()) {
                    q.pop();
                    cout << "Order Served..." << endl;
                }
                else {
                    cout << "The queue is empty..." << endl;
                }
                break;
            }
            case 0: {
                cout << "Exiting the program..." << endl;
                break;
            }
            default: {
                cout << "Enter correct input..." << endl;
            }
        }
    } while(ch!=0);
    return 0;
}
