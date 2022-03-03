/*
257. Binary Tree Paths
Easy

Given the root of a binary tree, return all root-to-leaf paths in any order.

A leaf is a node with no children.

 

Example 1:


Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
Example 2:

Input: root = [1]
Output: ["1"]
 

Constraints:

The number of nodes in the tree is in the range [1, 100].
-100 <= Node.val <= 100

*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

/*class Solution {
public:
    void construct_paths(TreeNode* root, string path, vector<string> &paths){
        if(root!=NULL){
            path += to_string(root->val);
            if((root->left == NULL) && (root->right == NULL)) 
                paths.push_back(path);
            else {
                path += "->";
                construct_paths(root->left, path, paths);
                construct_paths(root->right, path, paths);
            }
        }
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        construct_paths(root, "", paths);
        return paths;
    }
};*/
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        helper(root, "", res);
        return res;
    }
    
    void helper(TreeNode* root, string curr, vector<string>& res) {
        if (!root) return;
        curr += to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(curr);
            return;
        }
        curr += "->";
        helper(root->left, curr, res);
        helper(root->right, curr, res);
    }
};