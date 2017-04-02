#include <iostream>
#include <stdio.h>
#include <time.h>
#include "planet.h"
#include "randomgenerators.h"

int main()
{
    Planet planet(80, 4, 18);

    planet.calculate_fitnesses();

    planet.describe();

    return 0;
}
