#include<iostream>
using namespace std;
#define n 30

class queue{
    int* arr;
    int front;
    int back;

    public:
     queue()
     {
        arr = new int[n];
        front = -1;
        back = -1;
     }

     bool isEmpty()
     {
        if(front==-1 || front>back)
        {
            return true;
        }
        else
          return false;
     }

     bool isFull()
     {
        if(back==n-1)
        {
            return true;
        }
        return false;
     }

     void enqueue(int x)
     {
        if(isFull())
        {
            cout << "queue is full"<<endl;
            return;
        }
        back++;
        arr[back]=x;
        if(front==-1)
        {
            front++;
        }
     }

     void dequeue()
     {
        if(isEmpty())
        {
            cout << "queue is empty"<<endl;
            return;
        }
        front++;
     }

     int peek()
     {
        if(isEmpty())
        {
            cout << "queue is empty"<<endl;
            return -1;
        }
        return arr[front];
     }
};

int main()
{
    queue q1;
    //cout << q1.isFull()<<endl;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    //q1.enqueue(4);
    //q1.enqueue(5);
    q1.dequeue();
    q1.dequeue();
    //q1.dequeue();
   // q1.enqueue(3);
    cout << q1.peek()<<endl;
}

/*
//implementation of queue without using class

#include <bits/stdc++.h>
using namespace std;
int n;
int arr[1000];
int front=-1;
int rear=-1;

bool isEmpty()
{
    if(front==-1 || front>rear){
        return true;
    }
    else
    return false;
}

bool isFull()
{
    if(rear==n-1)
    {
        return true;
    }
    else
    return false;
}
void enqueue(int x)
{
    if(isFull())
    {
        cout << "queue is full" << endl;
        return;
    }
    rear++;
    arr[rear]=x;
    if(front==-1)
    {
        front++;
    }
}
void dequeue()
{
    if(isEmpty())
    {
        cout << "queue is empty" << endl;
        return;
    }
    front++;
}
int peek()
{
    if(isEmpty())
    {
        cout << "queue is empty " << endl;
        return -1;
    }
    return arr[front];
}

int main()
{
    
    cout << "Enter the size of the queue: ";
    cin >> n;
    arr[n];
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    dequeue();
    dequeue();
    dequeue();
    cout << peek();
    
}

*/