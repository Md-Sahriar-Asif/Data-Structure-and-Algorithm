// Flatten a binary tree

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void flatten(Node* root){
    if(root == NULL || (root->left==NULL && root->right==NULL)){
        return;
    }
    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* t = root->right;
        while(t->right != NULL){
            t=t->right;
        }
        t->right = temp;
    }

    flatten(root->right);
}

void inorderPrint(Node* root){
    if(root==NULL)
        return;
    
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    Node* root = new Node(4);
    root->left = new Node(9);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    flatten(root);
    inorderPrint(root);

}

/*
given a binary tree, flatten it into linked list inplace. After flattening,
left of each node should point to NULL and right should contain next node
in pre-order sequence, (not allowed to use other data structures)
*/

/* Strategy
-recursively, flatten the left then right subtrees
-Strore the left and right tail
-Store right subtree in 'temp' & make left subtree as right subtree
- join right subtree with left tail
- return right tail
*/