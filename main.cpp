#include <iostream>
#include <stdio.h>
#include <time.h>
#include "planet.h"
#include "randomgenerators.h"

int main()
{
    Planet planet(30, 500, 1234);

    static const int GENERATION_NUMBER {10000};

    for(int i {0}; i < GENERATION_NUMBER; i++)
    {
        planet.calculate_fitnesses();
        planet.select_bests();
        planet.mate_bests();
        planet.insert_children();
        planet.mutate();
    }

    planet.describe();

    return 0;
}
