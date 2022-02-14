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
class Solution {
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val, second->val);
    }
    
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(pre && pre->val > root->val){
            if(!first) first = pre;
            second = root;
        }
        pre = root;
        inorder(root->right);
    }
    
private:
    TreeNode* pre;
    TreeNode* first;
    TreeNode* second;
};