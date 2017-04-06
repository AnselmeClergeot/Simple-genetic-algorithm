#include "randomnumgenerator.h"
#include <time.h>
#include <stdlib.h>

RandomNumGenerator::RandomNumGenerator()
{

}

double RandomNumGenerator::get_real_between(const double taken_min, const double taken_max)
{
    return (rand()/static_cast<double>(RAND_MAX) * (taken_max - taken_min) + taken_min);
}

void RandomNumGenerator::initialize()
{
    srand(time(NULL));
}
