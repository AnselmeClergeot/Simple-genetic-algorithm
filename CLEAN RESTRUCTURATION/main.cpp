#include <iostream>
#include "geneticsolver.h"
#include "randomnumgenerator.h"

using namespace std;

int main()
{
    RandomNumGenerator::initialize();
    Individual indiv(12);

    std::cout << indiv;

    return 0;
}
