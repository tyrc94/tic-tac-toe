#include <utility>
#include <vector>
#include <algorithm>
#include "node.cpp"
#include "game_over.cpp"

using namespace std;

struct AI{

};

void min_value(Node* node);
void max_value(Node* node);

pair<int, int> move_ai(AI ai, vector <vector <int>> board){
    Node root;
    root.state = board;
    root.player = 1;
    max_value(&root);
    Node move;
    move.score = -10;
    for(Node child : root.children){
        if(child.score > move.score){
            move = child;
        }
    }
    return move.move;
}

void min_value(Node* node){
    int game_state = game_over(node -> state);
    if(game_state > -1){
        if(game_state == 1){
            node -> score = -1;
        } else if (game_state == 0){
            node -> score = 0;
        } else {
            node -> score = 1;
        }
        return;
    }
    expand(node);
    int score = 10;
    for(Node child : node -> children){
        max_value(&child);
        score = min(score, child.score);
    }
    node -> score = score;
}

void max_value(Node* node){
    int game_state = game_over(node -> state);
    if(game_state > -1){
        if(game_state == 1){
            node -> score = -1;
        } else if (game_state == 0){
            node -> score = 0;
        } else {
            node -> score = 1;
        }
        return;
    }
    expand(node);
    int score = -10;
    for(Node child : node -> children){
        min_value(&child);
        score = max(score, child.score);
    }
    node -> score = score;
}