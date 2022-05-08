//
// Created by 97252 on 4/25/2022.
//


#include <sstream>
#include "Assassin.hpp"

using namespace std;
using namespace coup;


Assassin::Assassin(Game &game, const string& name) : Player(game, name) {

    //Throw an exception if a new player trying to join the game when the game is full
    const int  six = 6;
    if (game.size >= six ){
        throw invalid_argument("Max player in the game is 6 !");
    }


    //Throw an exception if a new player trying to join the game when the game is already started
    if(game.start){
        throw invalid_argument("Game is already start !");
    }


    this->player_name = name;
    game.player.push_back(name);
    game.size++;

    //The game has the minimum to start
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










