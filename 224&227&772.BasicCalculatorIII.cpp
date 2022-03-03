/*
772. Basic Calculator III
Hard

Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "1+1"
Output: 2
Example 2:

Input: s = "6-4/2"
Output: 4
Example 3:

Input: s = "2*(5+5*2)/3+(6/2+8)"
Output: 21
 

Constraints:

1 <= s <= 104
s consists of digits, '+', '-', '*', '/', '(', and ')'.
s is a valid expression.
*/
class Solution {
public:
    int calculate(string s) {
        queue<char> q;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                q.push(s[i]);
        }
        q.push(' ');
        
        return helper(q);
            
    }
    
    int helper(queue<char>& q) {
        int prev = 0, num = 0, sum  = 0;
        char op = '+';
        
        while(!q.empty()) {
            char ch = q.front();
            q.pop();
            
            if (ch >= '0' && ch <= '9') {
                num = num * 10 + (ch -'0');
            }else if (ch == '(') {
                num = helper(q);
            }else {
                switch(op) {
                    case '+':
                        sum += prev;
                        prev = num;
                        break;
                    case '-':
                        sum += prev;
                        prev = -num;
                        break;
                    case '*':
                        prev *= num;
                        break;
                    case '/':
                        prev /= num;
                        break;
                }
                if (ch == ')') break;
                num = 0;
                op = ch;
                
            }
                
        }
        return sum + prev;
    
    }
};