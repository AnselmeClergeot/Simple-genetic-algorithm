#include "fitnesscalculator.h"
#include <cmath>

FitnessCalculator::FitnessCalculator(const int wanted_value) : m_wanted_value(wanted_value)
{

}

void FitnessCalculator::calculate_fitness_of(Individual &individual) const
{
    int value_of_individual {0};
    int max_error_possible { std::max(m_wanted_value, std::abs(m_wanted_value - 9 * individual.get_chromosome_length())) };

    for(int i = 0; i < individual.get_chromosome_length(); i++)
    {
        value_of_individual += individual.get_gene(i);
    }

    int error { std::abs(value_of_individual - m_wanted_value) };

    double fitness {(max_error_possible - error) / static_cast<double>(max_error_possible) * 100};

    individual.set_fitness(fitness);
}
