#include "fitnesscalculator.h"
#include <cassert>

FitnessCalculator::FitnessCalculator(std::vector<Individual> *population) : m_population(population)
{

}

void FitnessCalculator::set_searched_sum(const int sum)
{
    m_wanted_sum = sum;
}

void FitnessCalculator::calculate_all_fitnesses()
{
    assert(!m_population->empty());

    const int max_error_possible { std::max(static_cast<int>(m_wanted_sum), std::abs(static_cast<int>(m_wanted_sum - 9 * m_population->at(0).get_chromosome_length()))) };

    for(Individual &indiv : *m_population)
    {
        int value_of_individual {0};

        for(unsigned short gene : indiv.m_genes)
        {
            value_of_individual += gene;
        }

        if(value_of_individual == m_wanted_sum)
        {
            indiv.set_operational(true);
            indiv.set_fitness(1000);
            continue;
        }
        else
            indiv.set_operational(false);


        const int error { std::abs(static_cast<int>(value_of_individual - m_wanted_sum)) };

        const double fitness {(max_error_possible - error) / static_cast<double>(max_error_possible) * 1000};

        indiv.set_fitness(fitness);
    }
}
