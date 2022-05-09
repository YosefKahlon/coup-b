//
// Created by 97252 on 4/25/2022.
//
#include "Player.hpp"

#include <utility>

using namespace coup;

coup::Player::Player(coup::Game &game, string name) {
    this->p_game = &game;
    this->money = 0;
    this->player_name = std::move(name);
    this->action = Start;
    this->p = nullptr;
    this->pos = 0;

}

/**
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

    //Throw an exception if a player trying to make the first move but the game does not have the minimum players to start
    if (!this->p_game->min) {
        throw invalid_argument("Must 2 player to start the game !");
    }

    //The game is start new player can't join the game
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

    set_coins(1);
    set_Action(Income);
    this->p_game->end_my_turn(true);

}


/**
 * Action:
 * the player choose to take two coins to his pile
 *
 * If it's not his turn throw exception !
 */
void coup::Player::foreign_aid() {

    //Throw an exception if a player trying to make the first move but the game does not have the minimum players to start
    if (!this->p_game->min) {
        throw invalid_argument("Must 2 player to start the game !");
    }

    //The game is start new player can't join the game
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
    set_coins(2);
    this->p_game->end_my_turn(true);
}


void coup::Player::coup(Player &player) {
    const int seven = 7;
    const int three = 3;

    //Throw an exception if it's not the turn of this player
    if (this->p_game->turn() != this->player_name) {
        throw invalid_argument("Not your turn !");
    }

    //Throw an exception if a player trying to make a coup on player that's not in the game anymore
    if (player.get_Action() == Out) {
        throw invalid_argument("PLAYER IS ALREADY DEAD!");
    }

    int player_position = find_p(player.get_name());
    player.set_pos(player_position);


    //------------------- Assassin coup  cost 3 coins -------------------------------

    if (role() == "Assassin" && coins() < seven && coins() >= three) {


        this->set_Action(Assassination);
        player.set_Action(Out);
        set_coins(-three);


        //Remember this player, and his position on the list
        set_player(&(player));


        //Remove from the game
        out_from_game(player.get_pos());

        //two cases:
        //the position of the player is before my position --> need to increase the index turn with the new size
        //the position of the player is after my position --> same index turn with the new size
        if (find_p(get_name()) < player_position) {
            this->p_game->end_my_turn(true);
        } else {
            this->p_game->end_my_turn(false);
        }



        //Find the winner// winner can be found only after coup
        if (p_game->size == 1) {
            p_game->end_my_turn(true);
            p_game->win = true;
        }

        return;
    }

    //Throw an exception if Assassin does not has enough money
    if (role() == "Assassin" && coins() < three) {
        throw runtime_error("Not enough money for this operation !");
    }
    //Throw an exception if The player dose not has enough money
    if (coins() < seven) {
        throw runtime_error("Not enough money for this operation !");
    }


    //------------------- Regular coup  cost 7 coins -------------------------------

    set_coins(-seven);
    this->set_Action(Normal_coup);
    player.set_Action(Out);
    out_from_game(player.get_pos());



    //two cases:
    //the position of the player is before my position --> need to increase the index turn with the new size
    //the position of the player is after my position --> same index turn with the new size
    if (find_p(get_name()) < player_position) {
        this->p_game->end_my_turn(true);

    } else {
        this->p_game->end_my_turn(false);
    }

    //Find the winner // winner can be found only after coup
    if (p_game->size == 1) {
        p_game->end_my_turn(true);
        p_game->win = true;
    }
}


void coup::Player::set_coins(int num) {
    this->money += num;
}

string coup::Player::get_name() {
    return this->player_name;
}

void coup::Player::out_from_game(int pos) {
    this->p_game->player.erase(this->p_game->player.begin() + pos);
    this->p_game->size--;
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


int Player::find_p(const string &basicString) {
    int position = 0;
    for (::size_t i = 0; i < p_game->size; ++i) {
        if (p_game->player.at(i) == basicString) {
            position = i;
            break;
        }
    }
    return position;
}


















