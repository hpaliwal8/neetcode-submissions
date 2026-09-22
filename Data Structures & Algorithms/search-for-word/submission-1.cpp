class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int ROWS = board.size();
        int COLS = board[0].size();

        vector<vector<bool>> visited(ROWS, vector<bool>(COLS, false));

        for(int i=0;i<ROWS;i++) {
            for(int j=0;j<COLS;j++) {
                if(dfs(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int i, int j, int idx) {
        if(idx == word.size()) {
            return true;
        }

        if(i<0 || i>= board.size() || j<0 || j>=board[0].size() || visited[i][j] || board[i][j] != word[idx]) {
            return false;
        }

        visited[i][j] = true;

        bool res = dfs(board, word, visited, i + 1, j, idx + 1) || 
            dfs(board, word, visited, i - 1, j, idx + 1) || 
            dfs(board, word, visited, i, j + 1, idx + 1) || 
            dfs(board, word, visited, i, j - 1, idx + 1);

        visited[i][j] = false;
        return res;
        
    }
};
