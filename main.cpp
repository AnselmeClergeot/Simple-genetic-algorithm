#include <iostream>
#include <stdio.h>
#include <time.h>
#include "planet.h"
#include "randomgenerators.h"

int main()
{
    Planet planet(10, 15, 42);

    static const int GENERATION_NUMBER {15};

    for(int i {0}; i < GENERATION_NUMBER; i++)
    {
        std::cout << "Generation number " << i+1 << " :" << std::endl << std::endl;

        planet.calculate_fitnesses();
        planet.select_bests();
        planet.mate_bests();
        planet.insert_children();
        planet.mutate();
        planet.describe();

        std::cout << std::endl;
    }

    return 0;
}
