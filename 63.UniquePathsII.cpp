class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> f_(m, vector<int>(n, 0));
        f_[0][0] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (obstacleGrid[i][j] == 1 || (i == 0 && j == 0)) 
                    continue;
                else
                    f_[i][j] = (i > 0 ? f_[i-1][j] : 0) + (j>0 ? f_[i][j-1]:0);
            }
        }
        return f_[m-1][n-1];
    }
};