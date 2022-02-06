//
// Created by DeanSu on 2019/8/29.
//
#include "deleteList.h"
void deleteList(Node * head){

    Node *curr = head;
    Node *n;
    if(head == NULL)
        return;
    while (curr != NULL) {
        n = curr->next;
        delete (curr);
        curr = n;
    }
    head =  NULL;
    if(head == NULL)
        cout<<"List delete done"<<endl;
}
