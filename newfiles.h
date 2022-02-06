//
// Created by DeanSu on 2019/8/29.
//

#ifndef LEETCODE_NEWFILES_H
#define LEETCODE_NEWFILES_H
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <unordered_map>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/* The structure of a BST Node is as follows:*/
struct NodeBST {
    int data;
    NodeBST* right;
    NodeBST* left;

    NodeBST(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
#endif //LEETCODE_NEWFILES_H
