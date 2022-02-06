#include<bits/stdc++.h>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<vector<char>> d(10);
        d[0] = {' '};
        d[1] = {};
        d[2] = {'a', 'b', 'c'};
        d[3] = {'d', 'e', 'f'};
        d[4] = {'g', 'h', 'i'};
        d[5] = {'j', 'k', 'l'};
        d[6] = {'m', 'n', 'o'};
        d[7] = {'p', 'q', 'r', 's'};
        d[8] = {'t', 'u', 'v'};
        d[9] = {'w', 'x', 'y', 'z'};
        
        vector<string> res;
        string curr;
        dfs(digits, d, 0, curr, res);
        return  res;
    }
private:
    void dfs(const string& digits, const vector<vector<char>>& d, int l, string& curr, vector<string>& res) {
        if (l == digits.size())
        {
            res.push_back(curr);
            return;
        }
        for(const char c : d[digits[l] - '0']){
            curr.push_back(c);
            dfs(digits, d, l+1, curr, res);
            curr.pop_back();
        }
    }   
};