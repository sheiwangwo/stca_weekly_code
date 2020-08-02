class Solution {
public:

    bool validTicTacToe(vector<string>& board) {
        int numsX = 0;
        int numsO = 0;

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == 'X'){
                    numsX++;
                }else if(board[i][j] == 'O'){
                    numsO++;
                }
            }
        }
        if(numsO > numsX)
            return false;
        if(numsX-numsO > 1)
            return false;

        bool successX = false, successO = false;
        for(int i = 0; i < 3; i++){
            if(board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][0] == board[i][2] ){
                successX = true;
            }
            else if(board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][0] == board[i][2] ){
                successO = true;
            }

            if(board[0][i] == 'X' && board[0][i] == board[1][i] && board[0][i] == board[2][i] ){
                successX = true;
            }
            else if(board[0][i] == 'O' && board[0][i] == board[1][i] && board[0][i] == board[2][i] ){
                successO = true;
            }
        }
        if(board[0][0] == 'X' && board[0][0] == board[1][1] && board[0][0] == board[2][2] ){
            successX = true;
        }
        else if(board[0][0] == 'O' && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
            successO = true;
        }
        if(board[1][1] == 'X' && board[0][2] == board[1][1] && board[0][2] == board[2][0] ){
            successX = true;
        }
        else if(board[1][1] == 'O' && board[0][2] == board[1][1] && board[0][2] == board[2][0] ){
            successO = true;
        }

        if(successX && successO)
            return false;
        
        if(successO)
            return numsO == numsX;
        if(successX)
            return numsX == numsO+1;

        return true;
    }
};