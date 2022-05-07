//
// Created by 97252 on 4/25/2022.
//
#include "Player.hpp"

#include <utility>

using namespace coup;

/*
 * std::move is used to indicate that an object t may be "moved from", i.e. allowing the efficient transfer of resources from t to another object.

In particular, std::move produces an xvalue expression that identifies its argument t. It is exactly equivalent to a static_cast to an rvalue reference type.

Parameters
 */
coup::Player::Player(coup::Game &game, string name) {
    this->p_game = &game;
    this->money = 0;
    this->player_name = std::move(name);
    this->action = Start;


}

/**
 *
 * @return How many coins does this player have
 */
int coup::Player::coins() const {
    return this->money;
}


/**
 * Action:
 * the player choose to take one coin to his pile
 *
 * If it's not his turn throw exception !
 */
void coup::Player::income() {




    if(!this->p_game->min){
        throw invalid_argument("Must 2 player to start the game !");
    }

    p_game->start = true;

    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn()!= this->player_name) {
        throw invalid_argument("Not your turn !");

    }




    //Throw an exception if this player has more than 10 coins, and he has not made a coup
    const int ten = 10;
    if (coins() >= ten) {
        throw runtime_error("Player must make a coup operation when he have more then 10 coins ! ");
    }
    this->p_game->end_my_turn(true);
    set_coins(1);
    set_Action(Income);

}

void coup::Player::set_coins(int num) {
    this->money += num;
}


/**
 * Action:
 * the player choose to take two coins to his pile
 *
 * If it's not his turn throw exception !
 */
void coup::Player::foreign_aid() {


    if(!this->p_game->min){
        throw invalid_argument("Must 2 player to start the game !");
    }
    p_game->start = true;

    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn() != this->player_name) {
        throw invalid_argument("Not your turn !");
    }




    //Throw an exception if this player has more than 10 coins, and he has not made a coup
    const int ten = 10;
    if (coins() >= ten) {
        throw runtime_error("Player must make a coup operation when he have more then 10 coins ! ");
    }

    set_Action(Foreign_aid);
    this->p_game->end_my_turn(true);
    set_coins(2);

}


void coup::Player::coup(Player &player) {
    const int seven = 7;
    const int three = 3;

    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn()!= this->player_name) {
        throw invalid_argument("Not your turn !");
    }

    if(player.get_Action() == Out){
        throw invalid_argument("PLAYER IS ALREADY DEAD!");
    }




    //Assassin coup - can do when the assassin have more than 3 coins and less than 7
    if (role() == "Assassin" && coins() < seven && coins() >= three) {


        //set Action
        this->set_Action(Assassination);
        player.set_Action(Out);


        //set coin
        set_coins(-three);

        //remember this player
        set_player(&(player));


        int posi = find_p(player.get_name());


        player.set_pos(posi);

        out_from_game(player.get_pos());


        if(find_p(get_name()) < posi) {
            this->p_game->end_my_turn(true);
        }else{
            this->p_game->end_my_turn(false);
        }


        if (p_game->size == 1) {
            p_game->end_my_turn(true);
            p_game->win = true;
            return;
        }




        return;
    }

    if (role() == "Assassin" && coins() < three) {
        throw runtime_error("Not enough money for this operation !");
    }

    if (coins() < seven) {
        throw runtime_error("Not enough money for this operation !");
    }



    int posi = find_p(player.get_name());
   player.set_pos(posi);

    out_from_game(player.get_pos());
    set_coins(-seven);
    this->set_Action(Normal_coup);
    player.set_Action(Out);


    if(find_p(get_name()) < posi) {
        this->p_game->end_my_turn(true);

    }else{
        this->p_game->end_my_turn(false);
    }



    if (p_game->size == 1) {
        p_game->end_my_turn(true);
        p_game->win = true;
        return;
    }



}


string coup::Player::get_name() {
    return this->player_name;
}

void coup::Player::out_from_game(int pos) {
    this->p_game->player.erase(this->p_game->player.begin() + pos);
    this->p_game->size--;
  //  this->p_game->index++;
}

int Player::get_Action() const {
    return this->action;
}

void Player::set_Action(int act) {
    this->action = act;

}

Player &Player::get_player() {
    return *(this->p);
}

void Player::set_player(Player *player) {
    this->p = player;
}

int Player::get_pos() const {
    return this->pos;
}

void Player::set_pos(int posi) {
    this->pos = posi;
}

int Player::find_p(string basicString) {
    int posi = 0;
    for (::size_t i = 0; i < p_game->size; ++i) {
        if (p_game->player.at(i) == basicString){
            posi = i;
            break;
        }
    }
    return posi;
}


















