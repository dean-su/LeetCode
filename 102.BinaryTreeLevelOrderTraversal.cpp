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
/*class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(TreeNode* root, int depth, vector<vector<int>>& res) {
        if (!root) return;
        while(res.size() <= depth) res.push_back({});
        res[depth].push_back(root->val);
        dfs(root->left, depth+1, res);
        dfs(root->right,depth+1, res);
    }
};*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        vector<TreeNode*> curr, next;
        curr.push_back(root);
        while (!curr.empty()) {
            res.push_back({});
            for (auto node : curr) {
                res.back().push_back(node->val);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            swap(curr, next);
            next.clear();
        }
        return res;
    }
};

