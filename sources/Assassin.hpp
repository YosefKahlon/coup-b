//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_ASSASSIN_HPP
#define COUP_A_ASSASSIN_HPP


#include "Player.hpp"
#include "Game.hpp"
#include "string"
 namespace coup{

class Assassin : public Player {



public:


    Assassin(Game &game,  const string& name);


    string role() const override;





};

}
#endif //COUP_A_ASSASSIN_HPP
