#include "randomgenerators.h"
#include <time.h>
#include <stdlib.h>

RandomGenerators::RandomGenerators()
{

}

double RandomGenerators::real_between(const double min, const double max)
{
    return (rand()/static_cast<double>(RAND_MAX) * (max - min) + min);
}

void RandomGenerators::initialize()
{
    srand(time(NULL));
}
