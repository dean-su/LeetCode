//
// Created by DeanSu on 2019/8/29.
//
#include "push.h"
void push_front(Node **head, int v){
    Node *ele = new Node;
    ele->data = v;
    ele->next = (*head);
    (*head) = ele;
}

void push_front_listnode(ListNode **head, int v){
    ListNode *ele = new ListNode(v);
    //ele->val = v;
    ele->next = (*head);
    (*head) = ele;
}

void push_back(Node **head, int v){
    Node* ele = new Node;
    Node* curr = (*head);
    ele->data = v;
    ele->next = NULL;
    if(*head == NULL){
        (*head) = ele;
        (*head)->next = NULL;
        return;
    }
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ele;
}

void push_back_listnode(ListNode **head, int v){
    ListNode* ele = new ListNode(v);
    ListNode* curr = (*head);
    //ele->data = v;
    ele->next = NULL;
    if(*head == NULL){
        (*head) = ele;
        (*head)->next = NULL;
        return;
    }
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ele;
}