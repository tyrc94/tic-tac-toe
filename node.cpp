#include <iostream>
#include <vector>

using namespace std;

struct Node{
    vector <vector <int>> state;
    Node* parent = nullptr;
    int player;
    int score;
    vector <Node> children;
    pair<int, int> move;
};

void expand(Node* current_node) {
    for(int i = 0; i < current_node -> state.size(); i++){
        for(int j = 0; j < current_node -> state[i].size(); j++){
            if(current_node -> state[i][j] == 0){
                Node new_node;
                new_node.player = (current_node -> player == 1) ? 2 : 1;
                vector <vector <int>> new_state;
                new_state = current_node -> state;
                new_state[i][j] = new_node.player;
                new_node.state = new_state;
                new_node.parent = current_node;
                new_node.move = make_pair(i,j);
                current_node -> children.push_back(new_node);
            }
        }
    }
}


// int main(){
//     Node node;
//     node.state = {{1,0,0},{0,0,0},{1,1,1}};
//     node.children = {};
//     node.player = 1;
//     expand(&node);
//     cout << node.children.size() << endl;
//     for(Node& x : node.children){
//         expand(&x);
//     }
//     cout << "end" << endl;
// }
