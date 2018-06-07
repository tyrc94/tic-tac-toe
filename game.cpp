#include <iostream>
#include <vector>

using namespace std;

struct Game{
    vector <vector<int>> board;
    int current_player;
};

void make_move(Game g, int x, int y){
    int board_size = g.board.size();
    if(x < 0 || x >= board_size) {
        throw new exception();
    }
    if(y < 0 || y >= board_size){
        throw new exception();
    }
    g.board[x][y] = g.current_player;
    g.current_player = (g.current_player == 1) ? 1 : 2;
}

int game_over(Game g){
    if(g.board[0][0] != 0 && g.board[0][0] == g.board[0][1] && g.board[0][0] == g.board[0][2]){
        return g.board[0][0];
    }
    if(g.board[0][0] != 0 && g.board[0][0] == g.board[1][1] && g.board[0][0] == g.board[2][2]){
        return g.board[0][0];
    }
    if(g.board[0][0] != 0 && g.board[0][0] == g.board[1][0] && g.board[0][0] == g.board[2][0]){
        return g.board[0][0];
    }
    if(g.board[1][0] != 0 && g.board[1][0] == g.board[1][1] && g.board[1][0] == g.board[0][2]){
        return g.board[0][0];
    }
    if(g.board[2][0] != 0 && g.board[2][0] == g.board[2][1] && g.board[2][0] == g.board[2][2]){
        return g.board[0][0];
    }    
    if(g.board[0][1] != 0 && g.board[0][1] == g.board[1][1] && g.board[0][1] == g.board[2][1]){
        return g.board[0][0];
    }
    if(g.board[0][2] != 0 && g.board[0][2] == g.board[1][2] && g.board[0][2] == g.board[2][2]){
        return g.board[0][0];
    }    
    if(g.board[2][0] != 0 && g.board[2][0] == g.board[1][1] && g.board[2][0] == g.board[0][2]){
        return g.board[0][0];
    }
    for(int x = 0; x < g.board.size(); x++){
        for(int y = 0; y < g.board.size(); y++){
            if(g.board[x][y] == 0){
                return -1;
            }
        }
    }
    return 0;
}

void play_game(){
    int game_state = -1;
    while(game_state == -1){
        int x, y;
        cin >> x;
        cin >> y;
        cout << "You have played position (" << x << ", ";
        cout << y << ")" << endl;
        game_state = 1;
    }
}

void show_board(Game g){
    for(int x = 0; x < g.board.size(); x++){
        for(int y = 0; y < g.board[x].size(); y++){
            cout << g.board[x][y];
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    play_game();
}
