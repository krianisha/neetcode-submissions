class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>>row(9,vector<int>(9,0));
        vector<vector<int>>col(9,vector<int>(9,0));
        vector<vector<int>>grid(9,vector<int>(9,0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                if(board[i][j]=='.') continue;
                int number=board[i][j]-'0';
                int k=(i/3)*3+(j/3);
                if(row[i][number-1]||col[j][number-1]||grid[k][number-1]) 
                   return false;
                row[i][number-1]=1;
                col[j][number-1]=1;
                grid[k][number-1]=1;   
            }
        }
     return true;
    }
};
