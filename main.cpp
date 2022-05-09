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
    Duke duke{game_11, "Moshe"};
    Assassin assassin{game_11, "Yossi"};
    Ambassador ambassador{game_11, "Meirav"};
    Captain captain{game_11, "Reut"};
    Contessa contessa{game_11, "Gilad"};
    vector<Player *> Players = {&duke, &assassin, &ambassador, &captain, &contessa};
    cout << "-------------- Game start----------------- \n \n ";


    for (size_t j = 0; j < 3; j++) {
        for (size_t i = 0; i < Players.size(); i++) {
            Players.at(i)->income();
        }

    }

    cout << "--------------Money status ----------------- \n";
    cout << duke.get_name() << " -> " << duke.coins() << endl;
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << ambassador.get_name() << " -> " << ambassador.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;
    cout << contessa.get_name() << " -> " << contessa.coins() << endl;



    cout << "\n\n"
            "Duke - tax \n"
            "Assassin - coup Ambassador\n "
            "contessa block Assassin \n"
            "Ambassador love conteasa so he transfer her money\n "
            "capitan stay quite and taking 2 coins  \n "
            "conteasa take 1 coin \n \n";
    duke.tax();
    assassin.coup(ambassador);
    contessa.block(assassin);
    ambassador.transfer(duke, contessa);
    captain.foreign_aid();
    contessa.income();

    cout << "--------------Money status ----------------- \n";
    cout << duke.get_name() << " -> " << duke.coins() << endl;
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << ambassador.get_name() << " -> " << ambassador.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;
    cout << contessa.get_name() << " -> " << contessa.coins() << endl;

    cout << "\n\n"
            "Duke - tax   \n"
            "Assassin - foreign_aid  \n "
            "Ambassador - transfer \n "
            "capitan - income \n"
            "conteasa - foreign_aid \n"
            " duke block comteseasa \n \n";

    duke.tax();
    assassin.foreign_aid();
    ambassador.transfer(assassin, contessa);
    captain.income();
    contessa.foreign_aid();
    duke.block(contessa);

    cout << "--------------Money status ----------------- \n";
    cout << duke.get_name() << " -> " << duke.coins() << endl;
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << ambassador.get_name() << " -> " << ambassador.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;
    cout << contessa.get_name() << " -> " << contessa.coins() << endl;

    cout << "\n\n"
            "Duke -coup contensa   \n"
            "Assassin -taking 2 coins \n "
            "ambassador dont want to fight and take 2 coin  \n"
            "duke block ambassador \n "
            "capitan steal ambassador \n"
            "ambassador stop him \n"
            " \n \n";

    duke.coup(contessa);
    assassin.foreign_aid();
    ambassador.foreign_aid();
    duke.block(ambassador);
    captain.steal(ambassador);
    ambassador.block(captain);


    cout << "--------------Money status ----------------- \n";
    cout << duke.get_name() << " -> " << duke.coins() << endl;
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << ambassador.get_name() << " -> " << ambassador.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;

    cout << "\n\n"
            "Duke tax  \n"
            "Assassin coup ambassador  \n "
            "capitan steal from duke\n"
            " \n \n";

    duke.tax();
    assassin.coup(ambassador);
    captain.steal(duke);

    cout << "--------------Money status ----------------- \n";
    cout << duke.get_name() << " -> " << duke.coins() << endl;
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;

    cout << "\n\n"
            "Duke tax  \n"
            "Assassin foreign_aid  \n "
            "capitan coup duke \n"
            " \n \n";

    duke.tax();
    assassin.foreign_aid();
    captain.coup(duke);

    cout << "--------------Money status ----------------- \n";
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;


    cout << "\n\n"
            "Assassin - foreign_aid  \n "
            "capitan steal from assassin \n"
            " \n \n";

    assassin.foreign_aid();
    captain.steal(assassin);

    cout << "--------------Money status ----------------- \n";
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;

    cout << "\n\n"
            "Assassin - foreign_aid  \n "
            "capitan steal from assassin \n"
            " \n \n";

    assassin.foreign_aid();
    captain.steal(assassin);

    cout << "--------------Money status ----------------- \n";
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;
    cout << "\n\n"
            "Assassin - income  \n "
            "capitan foreign_aid\n"
            " \n \n";

    assassin.income();
    captain.foreign_aid();

    cout << "--------------Money status ----------------- \n";
    cout << assassin.get_name() << " -> " << assassin.coins() << endl;
    cout << captain.get_name() << " -> " << captain.coins() << endl;

    cout << "\n\n"
            "Assassin coup capitan  \n "
            " \n \n";
    assassin.coup(captain);

    cout << "-------------- Winner ----------------- \n";
    cout << game_11.winner() << endl;
}






