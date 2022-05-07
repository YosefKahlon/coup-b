//
// Created by 97252 on 4/25/2022.
//

#include <iostream>
#include "Duke.hpp"
#include "Player.hpp"
#include "Game.hpp"

using namespace coup;


Duke::Duke(Game &game, const string& name) : Player(game, name) {

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
string Duke::role() const {
    return "Duke";
}

/**
 * Action:
 * the player choose to take three coins to his pile
 */
void Duke::tax() {
    if(!this->p_game->min){
        throw invalid_argument("Must 2 player to start the game !");
    }
    p_game->start = true;


    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn() != this->player_name) {
        throw invalid_argument("Not your turn !");
    }



    //Throw an exception if this player has more than 10 coins, and he has not made a coup
    const int ten= 10;
    if (coins() >= ten) {
        throw runtime_error("Player must make a coup operation when he have more then 10 coins ! ");
    }


    set_Action(Tax);
    set_coins(3);
    this->p_game->end_my_turn(true);
}



void Duke::block(Player& player) {
    //Throw an exception if Duke trying to block wrong player
    if (player.get_Action() !=  Foreign_aid ){
        throw runtime_error("Duke cannot block this player operation ! ");
    }
    player.set_coins(-2);
    set_Action(duke_block_foreign_aid);
    player.set_Action(duke_block_me);

}








