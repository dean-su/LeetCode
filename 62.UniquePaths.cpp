/*
class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m < 0 || n < 0) return 0;
        if (m == 1 && n == 1) return 1;
        if(f_[m][n] > 0) return f_[m][n];
        int left_paths = uniquePaths(m-1, n);
        int top_paths = uniquePaths(m, n-1);
        f_[m][n] = left_paths + top_paths;
        return f_[m][n];
    }
    
private:
    unordered_map<int, unordered_map<int,int>> f_;
};
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        auto grid = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i == 0 || j == 0) {
                    grid[i][j] = 1;
                    continue;
                }
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
    }
};