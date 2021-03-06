class Solution {
public:
    void dfs(vector<vector<char>>& board, int currentX, int currentY){
        if(currentY >= board.size() || currentX >= board[0].size() || currentX < 0 || currentY < 0)
            return;
        
        if(board[currentY][currentX] == 'V' || board[currentY][currentX] == 'X')
            return;
        
        board[currentY][currentX] = 'V';
        
        dfs(board, currentX + 1, currentY);
        dfs(board, currentX - 1, currentY);
        dfs(board, currentX, currentY + 1);
        dfs(board, currentX, currentY - 1);
        
    }

    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;

        for(int i = 0; i < board.size(); i++){
            dfs(board, 0, i);
            dfs(board, board[0].size() - 1, i);
        }
        
        for(int i = 0; i < board[0].size(); i++){
            dfs(board, i, 0);
            dfs(board, i, board.size() - 1);
        }
        
        for(int y = 0; y < board.size(); y++){
            for(int x = 0; x < board[0].size(); x++){
                if(board[y][x] == 'V')
                    board[y][x] = 'O';
                else if(board[y][x] == 'O')
                    board[y][x] = 'X';
            }
        }  
    }
};