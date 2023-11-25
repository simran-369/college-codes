/* 
Assignment No.3
Title:- Circular Queue 
Problem Statement:- Implement Circular Queue using Array. Perform following operations on it.
a) Insertion (Enqueue)
b) Deletion (Dequeue)
c) Display
*/
//CODE:

#include<bits/stdc++.h>
using namespace std;

int const n=5;

class Queue {
private:
    int q[n], f, r;

public:
    //creating constructor
    Queue() {
        f = -1;
        r = -1;
    }

    void Enqueue(int x) {
        if (f == -1 && r == -1) {
            f = r = 0;
            q[r] = x;
        }
        else if ((r + 1) % n == f) {
            cout << "queue is full." << endl;
        }
        else {
            r = (r + 1) % n;
            q[r] = x;
        }
    }

    void Dequeue() {
        if (f == -1 && r == -1) {
            cout << "queue is Empty " << endl;
        }
        else if (f == r) {
            cout << "deleted element is: " << q[f] << endl;//single element
            f = r = -1;   //make q empty
        }
        else {
            cout << "deleted element is: " << q[f] << endl;
            f = (f + 1) % n;
        }
    }

    void Display() {
        int i = f;
        if (f == -1 && r == -1) {
            cout << "queue is Empty " << endl;
        }
        else {
            cout << "the given queue is: " << endl;
            while (i != r) {
                cout << q[i] << " ";
                i = (i + 1) % n;
            }
            cout << q[r];
            cout << endl;
        }
    }
};

int main() {
    Queue qu;
    int ch, x;
    do {
        cout << "press 1. for Enqueue" << endl;
        cout << "press 2. for Dequeue" << endl;
        cout << "press 3. for Display" << endl;
        cout << "press 4. for EXIT CODE " << endl;
        cout << "enter your choice : " << " ";
        cin >> ch;
        switch (ch) {
        case 1: {
            cout << "enter element to be inserted: ";
            cin >> x;
            qu.Enqueue(x);
            break;
        }
        case 2: {
            qu.Dequeue();
            break;
        }
        case 3: {
            qu.Display();
            break;
        }
        case 4: {
            cout << "code EXITED SUCCESSFULLY !" << endl;
            break;
        }
        }
    } while (ch != 4);
    return 0;
}

/*
***OUTPUT***

press 1 . for Enqueue
press 2 . for Dequeue
press 3 . for Display
press 4 . for EXIT CODE 
enter your choice :  1
enter element to be inserted :  56

enter your choice :  1
enter element to be inserted :  89

enter your choice :  1
enter element to be inserted :  54

enter your choice :  3
the given queue is :
56 89 54

enter your choice :  2
deleted element is :56

enter your choice :  3
the given queue is :
89 54

enter your choice :  2
deleted element is :89

enter your choice :  2
deleted element is :54

enter your choice :  3
queue is Empty

enter your choice :  4
code EXITED SUCCESSFULLY !
*/