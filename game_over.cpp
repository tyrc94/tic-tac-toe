#include <vector>

using namespace std;

int game_over(vector <vector <int>> board){
    if(board[0][0] != 0 && board[0][0] == board[0][1] && board[0][0] == board[0][2]){
        return board[0][0];
    }
    if(board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        return board[0][0];
    }
    if(board[0][0] != 0 && board[0][0] == board[1][0] && board[0][0] == board[2][0]){
        return board[0][0];
    }
    if(board[1][0] != 0 && board[1][0] == board[1][1] && board[1][0] == board[1][2]){
        return board[1][0];
    }
    if(board[2][0] != 0 && board[2][0] == board[2][1] && board[2][0] == board[2][2]){
        return board[2][0];
    }    
    if(board[0][1] != 0 && board[0][1] == board[1][1] && board[0][1] == board[2][1]){
        return board[0][1];
    }
    if(board[0][2] != 0 && board[0][2] == board[1][2] && board[0][2] == board[2][2]){
        return board[0][2];
    }    
    if(board[2][0] != 0 && board[2][0] == board[1][1] && board[2][0] == board[0][2]){
        return board[2][0];
    }
    for(int row = 0; row < board.size(); row++){
        for(int col = 0; col < board.size(); col++){
            if(board[row][col] == 0){
                return -1;
            }
        }
    }
    return 0;
}