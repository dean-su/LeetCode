class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;
        vector<string> res;
        for (const char ch : s) {
              l += (ch == '(');
              if (l == 0)
                r += (ch == ')');
              else
                l -= (ch == ')');
            }
       
        dfs(s, res, 0, l, r);
       
        return res;
    }
private:
    bool isValid(const string& s) {
        int i = 0;
        for(const char ch : s) {
            if (ch == '(') i++;
            if (ch == ')') i--;
            if (i < 0) return false;
        }
        return i == 0;
    }
    
    void dfs(const string& s, vector<string>& res, int start, int l, int r) {
        if(l == 0 && r == 0){
            if(isValid(s)) res.push_back(s);
            return;
        }
        
        for(int i = start; i < s.size(); i++) {
            if (i != start && s[i] == s[i-1]) continue;
            
            if (s[i] == '(' || s[i] == ')') {
                string curr = s;
                curr.erase(i, 1);
                if(r>0 && s[i] == ')'){
                    dfs(curr, res, i, l, r-1);
                }else if(l>0 && s[i] == '(') {
                    dfs(curr, res, i, l-1, r);
                }
            }
                
        }
    }
};