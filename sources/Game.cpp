//
// Created by 97252 on 4/25/2022.
//

#include <iostream>
#include "Game.hpp"
#include "stdexcept"
#include "stdio.h"

using namespace std;
using namespace coup;


coup::Game::Game() {
    this->min = false;
    this->start = false;
    this->win = false; // there is a winner
    this->size = 0; //number of player
    this->index = 0;

}

std::vector<std::string> coup::Game::players() const {

    return this->player;


}


std::string coup::Game::winner() {
    if (!win) {
        throw runtime_error("Game is over !");
    }

    return turn();
}

std::string coup::Game::turn() {
    return this->player.at(index);
}



void Game::end_my_turn(bool forward) {
    if (forward) {
        this->index = (this->index + 1) % this->size;
    }
    else {
        this->index = this->index % this->size;
    }
}




