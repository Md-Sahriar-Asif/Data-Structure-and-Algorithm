//Inserting ele at the beggining and ending of the LL
/*#include <bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
//struct Node* head;
void insert(Node** head ,int x){
    Node* temp = (Node*) malloc(sizeof(struct Node));
    temp->data=x;
    temp->next= *head;
    *head=temp;  
   
}
void print(Node* head){
    //Node* temp=head;
    cout << "element is: ";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}
int main()
{
	 Node* head = NULL; //empty list;
    int n, x;
    cout << "How many numbers? : ";
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cout << "Insert element: ";
        cin >> x;
        insert(&head, x);
        print(head);
    }
}
*/

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
    insertAtHead(head, 6);
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    display(head);
    insertAtHead(head, 4);
    insertAtHead(head, 5);
    display(head);
    cout << search(head, 6) << endl;
}

