// Height balanced Binary tree-(for each node the difference
//   between the heights of left and right subtree <=1)

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool isBalanced(Node* root, int* height){
    if(root==NULL)
        return true;
    
    int lh=0, rh=0;
    if(isBalanced(root->left, &lh) == false)
        return false;
    if(isBalanced(root->right, &rh) == false)
        return false;

    *height = max(lh, rh)+1;
    if(abs(lh-rh)<=1)
        return true;
    else
        return false;
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->right->right = new Node(7);

    Node* root2 = new Node(7);
    root2->left = new Node(4);
    root2->right = new Node(9);
    root2->left->left = new Node(3);
    root2->left->right = new Node(5);
    root2->left->right->right = new Node(6);

    int height=0;
    if(isBalanced(root2, &height))
        cout << "Tree is Balanced" << endl;
    else
        cout << "Tree is not Balanced" << endl;
}
