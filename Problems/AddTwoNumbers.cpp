//
// Created by DeanSu on 2019/9/10.
//You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
//You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//Example:
//
//Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
//Output: 7 -> 0 -> 8
//Explanation: 342 + 465 = 807.
#include "AddTwoNumbers.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *newList = new ListNode(0);
    ListNode *p1 = l1, *p2 = l2, *curr = newList, *head = newList;
    int c = 0;
    while(p1 != NULL || p2 != NULL){
        int x = (p1 != NULL ? p1->val : 0);
        int y = (p2 != NULL ? p2->val : 0);
        int sum = c + x + y;
        c = sum / 10;
        curr->next = new ListNode(sum%10);
        curr = curr->next;
        if (p1 != NULL) p1 = p1->next;
        if (p2 != NULL) p2 = p2->next;
    }

    if(c > 0)
        curr->next = new ListNode(c);

    return head->next;
}