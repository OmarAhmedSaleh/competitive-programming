class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ret = 0;
        int row = (int)board.size();
        int col = (int)board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
             if(board[i][j]=='X'){
                    ret++;
                 if((i&&board[i-1][j]=='x')||(j&&board[i][j-1]=='x')){
                     ret--;
                 }
                 board[i][j] = 'x';
             }   
            }
        }
        return ret;
    }
};
