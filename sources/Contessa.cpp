//
// Created by 97252 on 4/25/2022.
//

#include "Contessa.hpp"

using namespace coup;

Contessa::Contessa(Game &game, const string &name) : Player(game, name) {

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
  

    player.set_Action(Noting);


    this->set_Action(Block_cont);
}


