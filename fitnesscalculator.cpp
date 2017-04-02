#include "fitnesscalculator.h"
#include <cmath>

FitnessCalculator::FitnessCalculator(const int wanted_value) : m_wanted_value(wanted_value)
{

}

void FitnessCalculator::calculate_fitness_of(Individual &individual) const
{
    int value_of_individual {0};

    for(int i = 0; i < individual.get_chromosome_length(); i++)
    {
        value_of_individual += individual.get_gene(i);
    }

    int error { abs(value_of_individual - m_wanted_value) };

    int fitness { static_cast<double>(m_wanted_value - error)/m_wanted_value * 100 };

    individual.set_fitness(fitness);
}
