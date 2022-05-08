//
// Created by 97252 on 4/25/2022.
//

#include "Contessa.hpp"

using namespace coup;

Contessa::Contessa(Game &game, const string &name) : Player(game, name) {

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


string Contessa::role() const {
    return "Contessa";
}


void Contessa::block(Player &player) {


    if (player.get_Action() != Assassination) {
        throw runtime_error("Contessa cannot block this player operation !");
    }


    player.set_Action(Noting);




    // Bring back from the dead
    auto itPos = this->p_game->player.begin() + player.get_player().get_pos();

    this->p_game->player.insert(itPos, player.get_player().get_name());




    this->p_game->size++;


    if (find_p(player.get_player().get_name())  < find_p(player.get_name())){
        this->p_game->end_my_turn(true);
    }else{
        this->p_game->end_my_turn(false);
    }


    player.get_player().set_Action(Noting);


    this->set_Action(Block_cont);
}


