//
// Created by DeanSu on 2019/9/4.
//

#ifndef LEETCODE_STACKNODE_H
#define LEETCODE_STACKNODE_H

#include "../newfiles.h"
// A structure to represent a stack
class StackNode {
public:
    int data;
    StackNode* next;
    StackNode* newNode(int data);
    int isEmpty(StackNode* root);
    void push(StackNode** root, int data);
    int pop(StackNode** root);
    int peek(StackNode* root);
};
#endif //LEETCODE_STACKNODE_H
