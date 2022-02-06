//
// Created by DeanSu on 2019/8/29.
//
#include "deleteNode.h"
Node* deleteNode(Node *head, int x)
{
    //Your code here
    Node *p, *n = head;
    if(x == 1){
        return head->next;
    }

    while(--x){
        p = n;
        n = n->next;
    }
    if(p == NULL)
        return head;

    p->next = n->next;
    delete(n);
    return head;
}

Node* deleteNodeRecursive(Node *head, int x){
    if(!head)
        return head;
    if(x == 1)
        return head->next;
    head->next = deleteNode(head->next, x-1);
    return head;
}