class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, curr, res);
        return res;
    }
    
    void dfs(vector<int>& cans, int t, int s, vector<int> curr, vector<vector<int>>& res) {
        if (t == 0) {
            res.push_back(curr);
            return;
        }
        
        for( int i = s; i<cans.size(); i++) {
            if(cans[i]>t) return;
            if(i > s && cans[i] == cans[i-1]) continue;
            curr.push_back(cans[i]);
            dfs(cans, t-cans[i], i+1, curr, res);
            curr.pop_back();
        }
    }
};