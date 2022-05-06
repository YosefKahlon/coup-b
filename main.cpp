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


int main (){

    Game game_1{};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Contessa contessa{game_1, "Gilad"};
    Duke duke = {game_1, "d"};

   assassin.foreign_aid();
   ambassador.foreign_aid();
   contessa.foreign_aid();
   duke.foreign_aid();

   assassin.foreign_aid();
   ambassador.foreign_aid();
   contessa.foreign_aid();
   duke.foreign_aid();


   cout << game_1.size << endl;
   assassin.coup(ambassador);

  // contessa.block(assassin);
    cout << game_1.turn() << endl;
   cout << game_1.index << endl;
}






