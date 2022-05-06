//
// Created by 97252 on 4/25/2022.
//

#include "Captain.hpp"

using namespace coup;

Captain::Captain(Game &game, const string &name) : Player(game, name) {


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
string Captain::role() const {
    return "Captain";
}




/**
 * Action:
 * the player chose to steal coins from other player in the game
 * @param player
 */
void Captain::steal(Player &player) {

    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn()!= this->player_name) {
        throw invalid_argument("Not your turn !");
    }


    //Throw an exception if this player has more than 10 coins, and he has not made a coup
    const int ten = 10;
    if (coins() >= ten) {
        throw runtime_error("Player must make a coup operation when he have more then 10 coins ! ");
    }



    //Save the player in case of need to make any return
    set_player(&(player));

    const int two = 2;
    const int one = 1;

    //Case 1 the player that Capitan wants to steal from him has only one coin
    //Case 2 the player that Capitan wants to steal from him has more than 2 coins
    //Case 3 the player that Capitan wants to steal from him does not have enough coins
    if (player.coins() == one) {
        player.set_coins(-1);
        set_coins(1);

        player.set_Action(Robbed);
        set_Action(Steal_1);

        this->p_game->end_my_turn();
    } else if (player.coins() >= two) {
        player.set_coins(-2);
        set_coins(2);
        player.set_Action(Robbed);
        set_Action(Steal_2);

        this->p_game->end_my_turn();
    } else {
        throw runtime_error("Player not have enough money to steel !");
    }


}

/**
 * Action:
 * the player blocks a player from stealing from another player
 * @param player
 */
void Captain::block(Player &player) {
    //Throw an exception if Ambassador trying to block wrong player
    if (player.get_Action() != Steal_1 || player.get_Action() != Steal_2) {
        throw runtime_error("Captain cannot block this player operation !");
    }


    // case 1 steel 1 coin
    // case 2 steel 2 coins
    if (player.get_Action() == Steal_1) {
        player.set_coins(-1);
        player.get_player().set_coins(1);

    } else {
        player.set_coins(-2);
        player.get_player().set_coins(2);
    }


    set_Action(Block_steal);
    player.set_Action(Block_steal);

}



