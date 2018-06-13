#include <iostream>
#include <vector>
#include "ai.cpp"
#include <utility>
//#include "game_over.cpp"

using namespace std;

struct Game{
    vector <vector<int>> board = {
        {0,0,0},
        {0,0,0},
        {0,0,0}
    };
    int current_player = 1;
};

void show_board(Game* g);

void make_move(Game* g, int row, int col){
    int board_size = g -> board.size();
    if(row < 0 || row >= board_size) {
        throw new exception();
    }
    if(col < 0 || col >= board_size){
        throw new exception();
    }
    if(g -> board[row][col] > 0){
        throw new exception();
    }
    g -> board[row][col] = g -> current_player;
    g -> current_player = (g -> current_player == 1) ? 2 : 1;
}

void play_game(){
    int game_state = -1;
    Game game;
    AI ai;
    while(game_state == -1){
        int row, col;
        if(game.current_player == 1){
            cout << "It's player " << game.current_player << "'s turn:" << endl;
            cout << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
        } else {
            pair <int, int> ai_move = move_ai(ai, game.board);
            row = ai_move.first;
            col = ai_move.second;
            cout << row << endl;
            cout << col << endl;
        }
        
        try{
            make_move(&game, row, col);
        } catch(...) {
            cout << "Invalid move.\n" << endl;
            continue;
        } 
        
        cout << "You have played: Row " << row << ", Col " << col << endl;
        cout << endl;
        show_board(&game);
        game_state = game_over(game.board);
    }
    if(game_state == 1 || game_state == 2){
        cout << "Player " << game_state << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

void show_board(Game* g){
    for(int row = 0; row < g -> board.size(); row++){
        for(int col = 0; col < g -> board[row].size(); col++){
            cout << g -> board[row][col];
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    play_game();
}
