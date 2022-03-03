/*
221. Maximal Square
Medium

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

 

Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4
Example 2:


Input: matrix = [["0","1"],["1","0"]]
Output: 1
Example 3:

Input: matrix = [["0"]]
Output: 0
 

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int r = matrix.size();
        int c = matrix[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1, 0));
        int res = 0;
        
        for (int i = 1; i <= r; ++i) {
            for (int j = 1; j <= c; ++j) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res*res;
    }
};