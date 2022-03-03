/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        h = board.size();
        w = board[0].size();
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                if (search(board, word, 0, i, j))
                    return true;
            }
        }    
        return false;
    
    }
    
    bool search(vector<vector<char>>& board, const string& word, int d, int x, int y) {
        if (x < 0 || x == w || y < 0 || y == h || word[d] != board[y][x]) {
            return false;
        }
        
        if (d == word.length()-1) return true;
        
        char curr = board[y][x];
        board[y][x] = 0;
        bool found = search(board, word, d+1, x+1, y)
            || search(board, word, d+1, x-1, y)
            || search(board, word, d+1, x, y+1)
            || search(board, word, d+1, x, y-1);
        board[y][x] = curr;
        
        return found;
    }
    
    
private:
    int w, h;
};