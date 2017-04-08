#ifndef CROSSOVERMAKER_H
#define CROSSOVERMAKER_H
#include <vector>
#include "individual.h"

class CrossoverMaker
{
public:
    CrossoverMaker();

    static std::vector<Individual> single_point_crossover(const Individual &lhs_parent, const Individual &rhs_parent);
    static std::vector<Individual> two_points_crossover(const Individual &lhs_parent, const Individual &rhs_parent);
    static std::vector<Individual> uniform_crossover(const Individual &lhs_parent, const Individual &rhs_parent);


private:
};

#endif // CROSSOVERMAKER_H
