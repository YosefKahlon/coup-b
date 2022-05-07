/**
 * Demo program for Coup exercise
 *
 * @author: Tal Zichlinsky
 * @since: 2022-02
 */

#include "sources/Player.hpp"
#include "sources/Duke.hpp"
#include "sources/Assassin.hpp"
#include "sources/Ambassador.hpp"
#include "sources/Captain.hpp"
#include "sources/Contessa.hpp"
#include "sources/Game.hpp"

#include <exception>

using namespace coup;

#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;


int main() {
    Game game_11{}; // build game . add players
    Assassin assassin{game_11, "Yossi2"};
    Duke duke{game_11, "Moshe"};
    Assassin assassin2{game_11, "Yossi"};
    Ambassador ambassador{game_11, "Meirav"};
    Captain captain{game_11, "Reut"};
    Contessa contessa{game_11, "Gilad"};

    for (int i=0 ; i<6 ; i++){
        assassin.income();
        duke.income();
        assassin2.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }

    cout<< game_11.turn() <<endl;
    // each one has 6 coins
    assassin.coup(ambassador); // assassin 3
    cout<< game_11.turn() <<endl;
       contessa.block(assassin);
    cout<< game_11.turn() <<endl;
//    duke.tax(); //duke 9
//    assassin2.foreign_aid(); // assassin2 8
//    duke.block(assassin2); // assassin2 6
//    ambassador.transfer(assassin,contessa); // assassin 2, contessa 7
//    captain.steal(contessa); // contessa 5, captain 8
//    ambassador.block(captain); // contessa 7, captain 6
//    contessa.coup(duke); // contessa 0

}






