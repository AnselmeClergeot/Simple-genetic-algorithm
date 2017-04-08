#ifndef FITNESSCALCULATOR_H
#define FITNESSCALCULATOR_H
#include <vector>
#include "individual.h"

class FitnessCalculator
{
public:
    FitnessCalculator(std::vector<Individual> *population);

    void calculate_all_fitnesses();
    void set_searched_sum(const int sum);

private:
    unsigned int m_wanted_sum;
    std::vector<Individual> *m_population;
};

#endif // FITNESSCALCULATOR_H
