class Solution {
public:
    string decodeString(string s) {
        stack<int> countStr;
        stack<string> decodeStr;
        string currStr;
        int k = 0;
        
        for (auto ch : s) {
            if(isdigit(ch)) {
                k = k * 10 + ch - '0';
            }else if (ch == '[') {
                countStr.push(k);
                decodeStr.push(currStr);
                k = 0;
                currStr = "";
            }else if (ch == ']') {
                string temp = decodeStr.top();
                decodeStr.pop();
                
                for (int i = countStr.top(); i >0; i--) {
                    temp = temp + currStr;
                }
                
                countStr.pop();
                currStr = temp;
            }else {
                currStr = currStr + ch;
            }
        }
        
        return currStr;
    }
};