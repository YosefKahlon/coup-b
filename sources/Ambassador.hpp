//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_AMBASSADOR_HPP
#define COUP_A_AMBASSADOR_HPP

#include "Player.hpp"
#include "Game.hpp"
#include "string"

namespace coup {

    class Ambassador : public Player {

    public:
        string player_name;

    public:
        Ambassador(Game &game, const string& name);


        string role() const override;


        void transfer(Player& player1, Player& player2);


        //block steel
        void block(Player& player);


    };

}
#endif //COUP_A_AMBASSADOR_HPP
