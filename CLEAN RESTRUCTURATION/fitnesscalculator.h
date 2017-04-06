#ifndef FITNESSCALCULATOR_H
#define FITNESSCALCULATOR_H
#include <vector>
#include "individual.h"

class FitnessCalculator
{
public:
    FitnessCalculator(const unsigned int wanted_sum, std::vector<Individual> *individuals);

private:
    unsigned int m_wanted_sum;
    std::vector<Individual> *m_individuals;
};

#endif // FITNESSCALCULATOR_H
