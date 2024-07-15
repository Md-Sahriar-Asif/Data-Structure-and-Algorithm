// Left and Right view of a Binary tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }

};

void rightView(Node* root){
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        
        int n = q.size();
        for(int i=0; i<n; i++){
            Node* curr = q.front();
            q.pop();

            if(i==n-1)
              cout << curr->data << " ";  // value which we can see from the right side

            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}

void leftView(Node* root){
    if(root==NULL)
        return;
    
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n = q.size();
        for(int i=0; i<n; i++)
        {
            Node* curr = q.front();
            q.pop();
            if(i==0)
             cout << curr->data << " ";
            
            if(curr->left != NULL)
                q.push(curr->left);
            if(curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    struct Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //rightView(root);

    leftView(root);
}