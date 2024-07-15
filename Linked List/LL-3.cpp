// Reversing a LL
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val)
    {
        data=val;
        next=NULL;
    }

};

void insertAtHead(node* &head, int val)
{
    node* n = new node(val);
    n->next = head;
    head=n;
}

void insertAtTail(node* &head, int val) /*creating a LL or 
                                          inserting an element at end*/
{
    node* n = new node(val);

    if(head==NULL)
    {
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

node* reverse(node* &head) //reversing
{
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while(currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;   //moving one step further
        currptr = nextptr;
    }
    return prevptr;
}

bool search(node* head, int key)
{
    node* temp = head;
    while(temp != NULL)
    {
        if(temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main()
{
    node* head = NULL;
    insertAtHead(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);

    node* newhead = reverse(head);
    display(newhead);

    // head=newhead;   //or we can do that also
    // display(head);
}