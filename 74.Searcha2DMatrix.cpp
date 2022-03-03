class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size();
        int c = matrix[0].size();
        while (l < r) {
            int m = (l+r)/2;
            if (matrix[m/c][m%c] == target) {
                return true;
            }else if (matrix[m/c][m%c] > target) {
                r = m;
            }else {
                l = m+1;
            }
        }
        return false;
    }
};