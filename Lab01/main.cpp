/* 
 * File:   main.cpp
 * Author: Jack
 * Purpose: call the correct classes
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
int main(int argc, char** argv) 
{
    char loop = 'y';
    while (loop == 'y')
    {
    Pokemon First;
    Pokemon Second;
    Colosseum colosseum;
    std::cout << "Player one build your Pokemon" << '\n';
    colosseum.userBuild(First);
    std::cout << "Player two build your Pokemon" << '\n';
    colosseum.userBuild(Second);
    colosseum.play(First, Second);
    std::cout << "Want to play again? [y/n]";
    std::cin >> loop;
    }
    return 0;
}

