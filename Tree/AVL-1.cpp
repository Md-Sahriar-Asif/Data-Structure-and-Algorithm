#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val){
        key = val;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

int getHeight(Node* n){
    if(n==NULL)
        return 0;

    return n->height;
}

int getBalanceFactor(Node* n){
    if(n==NULL)
        return 0;

    return getHeight(n->left) - getHeight(n->right);
}

Node* rightRotate(Node* y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

Node* leftRotate(Node* x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

Node* insert(Node* node, int key){
    if(node == NULL){
        return new Node(key);
    }

    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    
    //return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int bf = getBalanceFactor(node);

    //Left left case
        if(bf > 1 && key < node->left->key)
          return rightRotate(node);

    //Right Right case
        if(bf < -1 && key > node->right->key)
          return leftRotate(node);
 
    //Left Right case
        if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    //Right Left case 
        if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

    return node;
}

void preorder(Node* root){
    if(root == NULL)
        return;
    
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    struct Node* root = NULL;

    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);

}


/* balancing a AVL tree after insertion
1. for left-left insertion - right rotate once with the first
imbalance node.
2. for right-right insertion - left rotate once with the first
inbalance node.
3. for left-right insertion - left rotate once with the child of 
first imbalance node and then right rotate oce with the first imbalance node
4. for right-left insertion - right rotate once with the child of 
first imbalance node and then left rotate once with the first imbalance node

*/