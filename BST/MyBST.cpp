//
// Created by DeanSu on 2019/9/7.
//
#include "MyBST.h"

void insert(NodeBST ** tree, int val)
{
    NodeBST *temp = NULL;
    if(!(*tree))
    {
        *tree = new NodeBST(val);
        return;
    }
    if(val < (*tree)->data)
    { insert(&(*tree)->left, val);}
    else if(val > (*tree)->data)
    { insert(&(*tree)->right, val);}
}

void inorder(NodeBST *root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

NodeBST* minValueNode(NodeBST *root){
    NodeBST *temp = root;
    while(temp && temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

NodeBST* deleteNode(NodeBST *root,  int x)
{
    // your code goes here
    if (root == NULL)
        return root;

    if (x < root->data){
        root->left = deleteNode(root->left, x);
    }else if(x > root->data){
        root->right = deleteNode(root->right, x);
    }else {

        if(root->left == NULL){
            NodeBST *temp = new NodeBST(x);
            temp = root->right;
            free(root);
            return temp;
        }else if (root->right == NULL){
            NodeBST *temp = new NodeBST(x);
            temp = root->left;
            free(root);
            return temp;
        }

        NodeBST *temp = minValueNode(temp->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}