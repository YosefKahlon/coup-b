//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_CONTESSA_HPP
#define COUP_A_CONTESSA_HPP

#include "Player.hpp"
#include "Game.hpp"
#include "string"

namespace coup {
    class Contessa : public Player {

    public:
        string player_name;


    public:
        Contessa(Game &game, const string& name);


        string role() const override;


        //block steel
        void block( Player& player);


    };
}
#endif //COUP_A_CONTESSA_HPP
