/* 
 * File:   main.cpp
 * Author: Jack
 *
 * Created on September 2, 2015, 10:46 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Colosseum.h"
#include "Pokemon.h"



/*
 * 
 */
int main(int argc, char** argv) {
    Pokemon First();
    Pokemon Second();
    Colosseum colosseum();
    std::cout << "Player one build your Pokemon";
    colosseum.userBuild(First);
    std::cout << "Player two build your Pokemon";
    colosseum.userBuild(Second);
    colosseum.play(First, Second);
    return 0;
}

