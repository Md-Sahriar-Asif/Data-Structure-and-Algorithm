// Level order traversal, sum of nodes at K(th) level 

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void printLevelOrder(Node* root)
{
    if(root==NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
            cout << node->data << " ";
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
        }
        else if(!q.empty())
            q.push(NULL);
    }
}

int sumAtK(Node* root, int k){
    if(root==NULL)
        return -1;
    
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while(!q.empty()){
        Node* node = q.front();
        q.pop();
        if(node != NULL){
         if(level==k)
            sum+=node->data;
         if(node->left)
            q.push(node->left);
         if(node->right)
            q.push(node->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int countNodes(Node* root) //counting all the nodes in a binary tree
{
    if(root==NULL)
        return -1;

    queue<Node*> q;
    q.push(root);
   // q.push(NULL);
    int count=1;
    
    while(!q.empty()){
        Node* node = q.front();
        q.pop();
       // if(node!=NULL){
            if(node->left){
                q.push(node->left);
                count++;
            }
            if(node->right){
                q.push(node->right);
                count++;
            }
        //}
    }
    return count;
}

int countNode(Node* root) // recursive approach 
{
    if(root==NULL)
    return 0;

    return countNode(root->left)+countNode(root->right)+1;
}

int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //printLevelOrder(root);

    //cout << sumAtK(root, 0) << endl;

    //cout << countNodes(root) << endl;
    cout << countNode(root);
}