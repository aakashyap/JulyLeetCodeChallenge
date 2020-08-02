/*

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3

*/

class Solution {
    int row;
    int col;
    int wordSize;
    vector<vector<bool>> visited;
    bool util(const vector<vector<char>>& board,int i,int j,const string &word,int k) {
        if (i == row|| i < 0 || j == col || j < 0) {
            return false;
        }
        
        if (!visited[i][j] && board[i][j] == word[k]) {
            visited[i][j] = true;
            if (k == wordSize-1) {
                return true;
            }
            if (util(board,i+1,j,word,k+1) || util(board,i-1,j,word,k+1) || util(board,i,j+1,word,k+1) ||util(board,i,j-1,word,k+1)) {
                visited[i][j] = false;
                return true;
            }
            visited[i][j] = false;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        wordSize = word.size();
        visited.resize(row,vector<bool>(col,false));
        for(int i = 0;i<row;++i) {
            for(int j = 0;j<col;++j) {
                if(util(board,i,j,word,0)) {
                    return true;
                }
            }
        }
        return false;
    }
};