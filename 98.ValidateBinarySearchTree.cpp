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
    bool isValidBST(TreeNode* root) {
        return inOrder(root, nullptr, nullptr);
    }
private:
    bool inOrder(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) return true;
        if(min != nullptr && root->val <= min->val) return false;
        if(max != nullptr && root->val >= max->val) return false;
        
        return inOrder(root->left, min, root) && inOrder(root->right, root, max);
        
    }
};