/*
216. Combination Sum III
Medium

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

 

Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:

Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
 

Constraints:

2 <= k <= 9
1 <= n <= 60
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> res;
        
        dfs(curr, res, k, n, 1);
        return res;
    }
    
    void dfs(vector<int> curr, vector<vector<int>>& res, int k, int n, int s) {
        if (k == 0 && n == 0) {
            res.push_back(curr);
            return;
        }
        
        for (int i = s; i <= 9; i++) {
            curr.push_back(i);
            dfs(curr, res, k -1, n-i, i+1);
            curr.pop_back();
        }
    }
};