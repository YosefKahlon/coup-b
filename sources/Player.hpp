//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_PLAYER_HPP
#define COUP_A_PLAYER_HPP

#include "string"
#include "iostream"

using namespace std;

#include "Game.hpp"

namespace coup {
    class Game;

    class Player {

    protected:
        string player_name;
        Game *p_game;
        int money;
        int action;
        Player *p;
        int pos;


    public:

        enum op {
            Start, // start game
            Income, // the player chose to take one coin and no one can block him
            Foreign_aid, // the player chose to take two coins and Duke can block him
            Tax, // special move of Duke, taking 3 coins without getting block
            duke_block_me,// player got a block by duke
            duke_block_foreign_aid,// special move of Duke, block a player who chose to make foreign aid
            Normal_coup, //player make normal coup - 7 coins
            Assissn_coup,//assassin coup
            Assassination,//assassin coup
            Transfer,// special move of Ambassador, transfer one coin from one player to another
            Block_my_steal,//
            Block_steal,//
            Steal_1,//steal one coin
            Steal_2,//steal two coins
            Robbed,//capitan robbed a player
            Block_cap,//
            Block_cont,//
            Out,// player is out from game
            Noting,//
            Received_1_from_transfer,//
            Lost_1_from_transfer//
        };

        Player(Game &game, string name);


        int coins() const;


        void income();

        void set_coins(int num);

        void foreign_aid();

        void coup(Player &player);



        string get_name();

        void out_from_game(int pos);


        int get_Action() const;

        void set_Action(int act);

        Player &get_player();
        void set_player(Player *player);

        int get_pos() const;

        void set_pos(int posi);


        virtual string role() const = 0; //need to be overridden
        int find_p(const string& basicString);
    };
}

#endif //COUP_A_PLAYER_HPP
