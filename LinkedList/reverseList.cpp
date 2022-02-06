//
// Created by DeanSu on 2019/8/28.
//
#include "reverseList.h"
void printListNode1(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
ListNode* reverseList2(ListNode* head) {
    ListNode *pre = NULL;
    ListNode *curr = head;
    while(curr != NULL){
        ListNode *nextTemp = curr->next;
        nextTemp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = nextTemp;
    }
    head = pre;
    return head;
}

void reverseList1(ListNode** head) {
    ListNode *curr, *prev = NULL;
    curr = *head;
    if(curr == NULL or curr->next == NULL)
        return ;
    while (curr != NULL){
        ListNode *nextTemp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextTemp;
    }
    *head = prev;

}

void reverseList(ListNode** head) {
    ListNode *curr, *tail = NULL;
    curr = *head;
    if(curr == NULL or curr->next == NULL)
        return;
    tail = *head;
    while (tail->next != NULL)
        tail = tail->next;
    curr = (*head)->next;
    while (curr != tail->next){
        (*head)->next = tail->next;
        tail->next = *head;
        *head = curr;
        curr = (*head)->next;
    }
    *head = tail;
}

ListNode* reverseListRcursive(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* p = reverseListRcursive(head->next);
    head = head->next->next;
    head->next = NULL;
    return p;
}