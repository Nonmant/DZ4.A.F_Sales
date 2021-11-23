//https://contest.yandex.ru/contest/27665/problems/F/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    //! @brief name - product - count
    std::map<std::string, std::map<std::string, unsigned long long int>> people;

    unsigned long long int count;
    std::string name, product;
    while (input >> name >> product >> count){
        people[name][product]+=count;
    }

    for(const auto & person : people){
        output << person.first << ":\n";
        for(const auto & item : person.second){
            output << item.first << ' ' << item.second << '\n';
        }
    }
}
