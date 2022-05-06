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


int main () {
    Game game_6{}; // build game . add players
    Duke duke{game_6, "Moshe"};
    Assassin assassin{game_6, "Yossi"};
    Ambassador ambassador{game_6, "Meirav"};
    Captain captain{game_6, "Reut"};
    Contessa contessa{game_6, "Gilad"};

    for (int i = 0; i < 9; i++) {
        duke.income();
        assassin.income();
        ambassador.income();
        captain.income();
        contessa.income();
    }
//    // before transfering coins
//    CHECK_EQ(duke.coins(),9);
//    CHECK_EQ(assassin.coins(),9);
//    CHECK_EQ(ambassador.coins(),9);
//    CHECK_EQ(captain.coins(),9);
//    CHECK_EQ(contessa.coins(),9);

    duke.income(); // 10
    assassin.foreign_aid(); // 11
    cout<< game_6.index<<endl;
    ambassador.coup(captain); // 2
    cout<< game_6.index << endl;
//    captain.income(); // 10
//    contessa.coup(captain); // 2



}
