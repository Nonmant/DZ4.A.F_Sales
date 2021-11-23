#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_ENABLE_BENCHMARKING
#include "catch.hpp"

TEST_CASE("Catch operability", "[simple]"){
    REQUIRE(1+1 == 2);
}

#include "funcs.h"

TEST_CASE("test 1, file", "[simple]"){
    std::ofstream inputPrepare;
    inputPrepare.open ("input.txt", std::ofstream::trunc);
    inputPrepare<<
                "Ivanov paper 10\n"
 "Petrov pens 5\n"
 "Ivanov marker 3\n"
 "Ivanov paper 7\n"
 "Petrov envelope 20\n"
 "Ivanov envelope 5"
            ;
    inputPrepare.close();

    std::ifstream input( "input.txt", std::ofstream::in);
    std::ofstream output("output.txt", std::ofstream::trunc);
    parseFile(input,output);
    input.close();
    output.close();

    std::ifstream outputCheck("output.txt", std::ofstream::in);
    std::stringstream buffer;
    buffer<<outputCheck.rdbuf();
    outputCheck.close();
    REQUIRE(buffer.str() ==
            "Ivanov:\n"
 "envelope 5\n"
 "marker 3\n"
 "paper 17\n"
 "Petrov:\n"
 "envelope 20\n"
 "pens 5\n"
    );
}

TEST_CASE("one block", ""){
    std::stringstream input(
            "Ivanov aaa 1\n"
 "Petrov aaa 2\n"
 "Sidorov aaa 3\n"
 "Ivanov aaa 6\n"
 "Petrov aaa 7\n"
 "Sidorov aaa 8\n"
 "Ivanov bbb 3\n"
 "Petrov bbb 7\n"
 "Sidorov aaa 345\n"
 "Ivanov ccc 45\n"
 "Petrov ddd 34\n"
 "Ziborov eee 234\n"
 "Ivanov aaa 45"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "Ivanov:\n"
 "aaa 52\n"
 "bbb 3\n"
 "ccc 45\n"
 "Petrov:\n"
 "aaa 9\n"
 "bbb 7\n"
 "ddd 34\n"
 "Sidorov:\n"
 "aaa 356\n"
 "Ziborov:\n"
 "eee 234\n"
    );
}

TEST_CASE("test 3", ""){
    std::stringstream input(
            "TKSNUU FKXYPUGQ 855146\n"
 "TKSNUU FKXYPUGQ 930060\n"
 "TKSNUU FKXYPUGQ 886973\n"
 "TKSNUU FKXYPUGQ 59344\n"
 "TKSNUU FKXYPUGQ 296343\n"
 "TKSNUU FKXYPUGQ 193166\n"
 "TKSNUU FKXYPUGQ 211696\n"
 "TKSNUU FKXYPUGQ 821064\n"
 "TKSNUU FKXYPUGQ 672846\n"
 "TKSNUU FKXYPUGQ 820341\n"
 "TKSNUU FKXYPUGQ 350693\n"
 "TKSNUU FKXYPUGQ 469538\n"
 "TKSNUU FKXYPUGQ 849069\n"
 "TKSNUU FKXYPUGQ 502007\n"
 "TKSNUU FKXYPUGQ 961595\n"
 "TKSNUU FKXYPUGQ 747271\n"
 "TKSNUU FKXYPUGQ 863648\n"
 "TKSNUU FKXYPUGQ 952069\n"
 "TKSNUU FKXYPUGQ 286019\n"
 "TKSNUU FKXYPUGQ 364841\n"
 "TKSNUU FKXYPUGQ 455930\n"
 "TKSNUU FKXYPUGQ 100486\n"
 "TKSNUU FKXYPUGQ 335026\n"
 "TKSNUU FKXYPUGQ 197672\n"
 "TKSNUU FKXYPUGQ 217640\n"
 "TKSNUU FKXYPUGQ 612549\n"
 "TKSNUU FKXYPUGQ 622501\n"
 "TKSNUU FKXYPUGQ 96554\n"
 "TKSNUU FKXYPUGQ 327166\n"
 "TKSNUU FKXYPUGQ 425399\n"
 "TKSNUU FKXYPUGQ 362309\n"
 "TKSNUU FKXYPUGQ 78477\n"
 "TKSNUU FKXYPUGQ 258916\n"
 "TKSNUU FKXYPUGQ 297923\n"
 "TKSNUU FKXYPUGQ 8891\n"
 "TKSNUU FKXYPUGQ 13639\n"
 "TKSNUU FKXYPUGQ 77308\n"
 "TKSNUU FKXYPUGQ 707620\n"
 "TKSNUU FKXYPUGQ 68205\n"
 "TKSNUU FKXYPUGQ 256702\n"
 "TKSNUU FKXYPUGQ 668334\n"
 "TKSNUU FKXYPUGQ 968673\n"
 "TKSNUU FKXYPUGQ 138125\n"
 "TKSNUU FKXYPUGQ 222904\n"
 "TKSNUU FKXYPUGQ 214091\n"
 "TKSNUU FKXYPUGQ 500231\n"
 "TKSNUU FKXYPUGQ 19611\n"
 "TKSNUU FKXYPUGQ 491343\n"
 "TKSNUU FKXYPUGQ 404307\n"
 "TKSNUU FKXYPUGQ 68367\n"
 "TKSNUU FKXYPUGQ 287107\n"
 "TKSNUU FKXYPUGQ 794935\n"
 "TKSNUU FKXYPUGQ 254217\n"
 "TKSNUU FKXYPUGQ 206370\n"
 "TKSNUU FKXYPUGQ 202761\n"
 "TKSNUU FKXYPUGQ 929017\n"
 "TKSNUU FKXYPUGQ 843359\n"
 "TKSNUU FKXYPUGQ 955269\n"
 "TKSNUU FKXYPUGQ 134139\n"
 "TKSNUU FKXYPUGQ 946168\n"
 "TKSNUU FKXYPUGQ 967781\n"
 "TKSNUU FKXYPUGQ 856474\n"
 "TKSNUU FKXYPUGQ 465070\n"
 "TKSNUU FKXYPUGQ 580526\n"
 "TKSNUU FKXYPUGQ 172109\n"
 "TKSNUU FKXYPUGQ 191703\n"
 "TKSNUU FKXYPUGQ 207916\n"
 "TKSNUU FKXYPUGQ 512264\n"
 "TKSNUU FKXYPUGQ 533081\n"
 "TKSNUU FKXYPUGQ 577208\n"
 "TKSNUU FKXYPUGQ 831389\n"
 "TKSNUU FKXYPUGQ 439158\n"
 "TKSNUU FKXYPUGQ 565633\n"
 "TKSNUU FKXYPUGQ 452643\n"
 "TKSNUU FKXYPUGQ 164426\n"
 "TKSNUU FKXYPUGQ 540743\n"
 "TKSNUU FKXYPUGQ 880704\n"
 "TKSNUU FKXYPUGQ 868529\n"
 "TKSNUU FKXYPUGQ 240742\n"
 "TKSNUU FKXYPUGQ 868865\n"
 "TKSNUU FKXYPUGQ 910442\n"
 "TKSNUU FKXYPUGQ 146737\n"
 "TKSNUU FKXYPUGQ 820984\n"
 "TKSNUU FKXYPUGQ 660948\n"
 "TKSNUU FKXYPUGQ 957975\n"
 "TKSNUU FKXYPUGQ 135847\n"
 "TKSNUU FKXYPUGQ 401865\n"
 "TKSNUU FKXYPUGQ 982859\n"
 "TKSNUU FKXYPUGQ 748454\n"
 "TKSNUU FKXYPUGQ 354734\n"
 "TKSNUU FKXYPUGQ 525638\n"
 "TKSNUU FKXYPUGQ 119140\n"
 "TKSNUU FKXYPUGQ 484816\n"
 "TKSNUU FKXYPUGQ 616539\n"
 "TKSNUU FKXYPUGQ 682553\n"
 "TKSNUU FKXYPUGQ 841541\n"
 "TKSNUU FKXYPUGQ 713063\n"
 "TKSNUU FKXYPUGQ 433453\n"
 "TKSNUU FKXYPUGQ 465340\n"
 "TKSNUU FKXYPUGQ 985635"
            );
    std::stringstream output;
    parseFile(input,output);
    REQUIRE(output.str() ==
    "TKSNUU:\n"
 "FKXYPUGQ 49769497\n"
    );
}
