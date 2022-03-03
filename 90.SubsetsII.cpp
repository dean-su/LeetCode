/*
90. Subsets II
Medium

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        dfs(nums, curr, res, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& curr, vector<vector<int>>& res, int s) {
        res.push_back(curr);
        
        for (int i = s; i < nums.size(); i++) {
            if (i > s && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            dfs(nums, curr, res, i+1);
            curr.pop_back();
        }
    }
};