#ifndef CROSSOVERS_H
#define CROSSOVERS_H
#include "individual.h"
#include <array>

class Crossovers
{
public:
    Crossovers();
    static std::array<Individual, 2> get_children(const Individual &lhs, const Individual &rhs);
};

#endif // CROSSOVERS_H
