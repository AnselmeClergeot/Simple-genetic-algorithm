#ifndef FITNESSCALCULATOR_H
#define FITNESSCALCULATOR_H
#include "individual.h"

class FitnessCalculator
{
public:
    FitnessCalculator(const int wanted_value);

    void calculate_fitness_of(Individual &individual) const;

private:
    int m_wanted_value;
};

#endif // FITNESSCALCULATOR_H
