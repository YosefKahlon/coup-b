//
// Created by 97252 on 4/25/2022.
//


#include <sstream>
#include "Assassin.hpp"

using namespace std;
using namespace coup;


Assassin::Assassin(Game &game, const string& name) : Player(game, name) {

    if (game.size >= 6 ){
        throw invalid_argument("Max player in the game is 6 !");
    }


    if(game.start){
        throw invalid_argument("Game is already start !");
    }

    this->player_name = name;
    game.player.push_back(name);
    set_Action(Start);
    set_pos(game.size);
    game.size++;
    if (game.size == 2){
        game.min = true;
    }
}

/**
 *
 * @return the rule of this player.
 */
string Assassin::role() const {
    return "Assassin";
}




void Assassin::tax() {
    if (role() == "Duke") {
        throw invalid_argument("Not your move !");
    }

}





