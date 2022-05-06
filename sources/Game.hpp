//
// Created by 97252 on 4/25/2022.
//

#ifndef COUP_A_GAME_HPP
#define COUP_A_GAME_HPP


#include "string"
#include "vector"
#include "unordered_map"

using namespace std;
namespace coup {
    class Game {
    public:
        vector<std::string> player;
        bool win;

        ::size_t size;
        ::size_t index;
        bool min ;
        bool start;

    public:

        Game();

        std::string turn();

        std::vector<std::string> players() const;

        std::string winner();


    };
}

#endif //COUP_A_GAME_HPP
