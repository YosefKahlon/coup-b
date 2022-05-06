//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_CAPTAIN_HPP
#define COUP_A_CAPTAIN_HPP

#include "Player.hpp"
#include "Game.hpp"
#include "string"

 namespace coup {

     class Captain : public Player {

     public:
         string player_name;


     public:
         Captain(Game &game, const string& name);


         string role() const override;

         void steal( Player& player);

         //block steel
         void block( Player &player);


     };
 }
#endif //COUP_A_CAPTAIN_HPP
