//
// Created by 97252 on 4/25/2022.
//

#include "Ambassador.hpp"
using namespace coup;
Ambassador::Ambassador(Game &game, const string& name): Player(game,name) {
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
string Ambassador::role() const {
    return "Ambassador";
}

/**
 * Action:
 * the Player chose to make a transfer from player1 to player2 of one coin
 * @param player1
 * @param player2
 */
void Ambassador::transfer( Player &player1,  Player& player2) {

    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn() != this->player_name) {
        throw invalid_argument("Not your turn !");
    }



    //Throw an exception if this player has more than 10 coins, and he has not made a coup
    const int ten= 10;
    if (coins() >=ten) {
        throw runtime_error("Player must make a coup operation when he have more then 10 coins ! ");
    }


    // Throw an exception if player1 not have enough coins
    if (player1.coins() < 1 ){
        throw runtime_error("The player does not have enough money to transfer !");
    }

    //The operation was successful
    player1.set_coins(-1);
    player2.set_coins(1);

    set_Action(Transfer);
    player1.set_Action(Lost_1_from_transfer);
    player2.set_Action(Received_1_from_transfer);

    this->p_game->index++;



}
/**
 * Action:
 * the player blocks a player from stealing from another player
 * @param player
 */
void Ambassador::block( Player& player) {


    //Throw an exception if Ambassador trying to block wrong player
    if (player.get_Action() != Steal_1 && player.get_Action() != Steal_2 ) {
        throw runtime_error("Ambassador cannot block this player operation !");
    }



    // case 1 steel 1 coin
    // case 2 steel 2 coins
    if(player.get_Action()== Steal_1){
        player.set_coins(-1);
        player.get_player().set_coins(1);


    }else {
        player.set_coins(-2);
        player.get_player().set_coins(2);
    }



    set_Action(Block_steal);
    player.set_Action(Block_steal);



}
