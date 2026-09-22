class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        unordered_set<int> row;
        unordered_set<int> col;
        unordered_set<int> box;
    
        for(int i=0;i<m;i++) {
            row.clear();
            for(int j=0;j<n;j++) {
                if (board[i][j]  == '.') {
                    continue;
                }
                if (row.contains(board[i][j])) {
                    return false;
                }
                row.insert(board[i][j]);
            }
        }

        for(int j=0;j<n;j++) {
            col.clear();
            for (int i=0;i<m;i++) {
                if (board[i][j]  == '.') {
                    continue;
                }
                if (col.contains(board[i][j])) {
                    return false;
                }
                col.insert(board[i][j]);
            }
        }

        for (int i=0;i<m;i+=3) {
            for (int j=0;j<n;j+=3) {
                box.clear();
                for(int br=i;br<i+3;br++) {
                    for(int bc=j;bc<j+3;bc++) {
                        if (board[br][bc] == '.') {
                            continue;
                        }
                        if (box.contains(board[br][bc])) {
                            return false;
                        }
                        box.insert(board[br][bc]);
                    }
                }                
            }
        }

        return true;
    }
};
