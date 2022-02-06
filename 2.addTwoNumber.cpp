#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head = ListNode(0);
        ListNode  *curr =  &head;
        int c = 0;
        while(l1 != NULL || l2 != NULL || c>0){
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            l1 = l1? l1->next : nullptr;
            l2 = l2? l2->next : nullptr;
            c = sum / 10;
            curr->next = new ListNode(sum%10);
            curr = curr->next;
        }
        
        return head.next;
    }
};

/**
 * Definition for singly-linked list.*/
  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
 // This prepends a new value at the beginning of the list
    void addValue(ListNode* head, int val){
        ListNode *n = new ListNode();   // create new Node
        n->val = val;             // set value
        n->next = head;         // make the node point to the next node.
                                //  If the list is empty, this is NULL, so the end of the list --> OK
        head = n;               // last but not least, make the head point at the new node.
    }

    // returns the first element in the list and deletes the Node.
    // caution, no error-checking here!
    int popValue(ListNode* head){
        ListNode *n = head;
        int ret = n->val;

        head = head->next;
        delete n;
        return ret;
    }

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

struct Node {
    int data;
    Node* next;
};
 
// This function prints contents of linked list
// starting from the given node
void printList(ListNode* n)
{
    while (n != NULL) {
        cout << n->val << " ";
        n = n->next;
    }
}

int main(){
    // l1 = [2,4,3], l2 = [5,6,4]
    //ListNode* l1 = {2,4,3}, ListNode* l2 = {5,6,4}
    ListNode* l1;
    addValue(l1, 2);
    addValue(l1, 4);

    printList(l1);
    
}