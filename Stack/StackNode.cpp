//
// Created by DeanSu on 2019/9/4.
//
#include "StackNode.h"
StackNode* StackNode::newNode(int data){
    StackNode* stackNode = new StackNode;
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int StackNode::isEmpty(StackNode *root) {
    return !(&root);
}

int StackNode::peek(StackNode *root) {
    if(isEmpty(root))
        return 0;
    return root->data;
}

void StackNode::push(StackNode **root, int data) {
    StackNode* stackNode = newNode(data);

    stackNode->next = *root;
    *root = stackNode;
}

int StackNode::pop(StackNode **root) {
    if (isEmpty(*root))
        return 0;
    StackNode *temp = *root;
    *root = (*root)->next;
    int x = temp->data;
    delete (temp);
    return x;
}