//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_DUKE_HPP
#define COUP_A_DUKE_HPP

#include "Player.hpp"
#include "Game.hpp"
#include "string"

namespace coup {

    class Duke : public Player {

    public:
        string player_name;

    public:

        Duke(Game &game, const string& name);

        string role() const override;


        //special action take 3 coins
        void tax();


        // block another player operation(foreign aid)
        void block(Player& player);

    };

}
#endif //COUP_A_DUKE_HPP
