// Catalan numbers application
//Q-2: given n nodes, with those how many possible BSTs can 
//      be formed and print those structure

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

int catalan(int n){  //printing catalan num sequence
    if(n<=1)
        return 1;
    
    int res = 0;
    for(int i=0; i<=n-1; i++){
        res += catalan(i) * catalan(n-i-1);
    }
    return res;
}

vector<Node*> constructTrees(int start, int end){  //Q:2
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }

    for(int i=start; i<=end; i++){
        vector<Node*> leftSubtrees = constructTrees(start, i-1);
        vector<Node*> rightSubtrees = constructTrees(i+1, end);

        for(int j=0; j<leftSubtrees.size(); j++){
            Node* left = leftSubtrees[j];
            for(int k=0; k<rightSubtrees.size(); k++){
                Node* right = rightSubtrees[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);

            }
        }
    }
    return trees;
}

void preorder(Node* root){
    if(root==NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    // for(int i=0; i<10; i++){
    //     cout << catalan(i) << " ";
    // }


    vector<Node*> totalTrees = constructTrees(1, 4);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i+1) << " : ";
        preorder(totalTrees[i]);
        cout << endl;
    }
    
}

/*
catalan numbers are a sequence of natural numbers that occur in 
various counting problems, often involving recursively defined objects

catalan sequence:
C0 = 1
C1 = 1
C2 = C0C1+C1C0 = 2
C3 = C0C2+C1C1+C2C0 = 5

*/

