#include <bits/stdc++.h>

/*
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                ans.push_back({i, j, abs(i - r0) + abs(j - c0)});

        sort(ans.begin(), ans.end(), [](vector<int>& c1, vector<int>& c2) {
            return c1[2] < c2[2];
        });

        for (vector<int>& d: ans) 
            d.pop_back();

        return ans;
    }
};
*/
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> res;
        for (int i = 0; i < rows; ++i)
            for(int j = 0; j < cols; ++j)
                res.push_back({i,j});
        
        sort(begin(res), end(res), [rCenter, cCenter](const auto& a, const auto& b){
            return abs(a[0]-rCenter) + abs(a[1]-cCenter) < abs(b[0]-rCenter) + abs(b[1]-cCenter);
        });
        return res;
    }
};