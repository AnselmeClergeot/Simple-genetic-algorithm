#include "planet.h"
#include "randomgenerators.h"
#include <algorithm>

Planet::Planet(const int individuals_number, const int chromosome_length, const int wanted_value) : m_individuals(), m_calculator(wanted_value)
{
    RandomGenerators::initialize();

    for(int i = 0; i < individuals_number; i++)
    {
        m_individuals.push_back(Individual(chromosome_length));
    }
}

void Planet::calculate_fitnesses()
{
    for(Individual &indiv : m_individuals)
    {
        m_calculator.calculate_fitness_of(indiv);
    }

    refresh_order();
}

void Planet::select_bests()
{

}

void Planet::mate_bests()
{

}

void Planet::insert_children()
{

}

void Planet::mutate()
{

}

void Planet::describe() const
{
    for(Individual indiv : m_individuals)
    {
        std::cout << indiv << std::endl;
    }
}

void Planet::refresh_order()
{
    std::sort(m_individuals.begin(), m_individuals.end(), IndividualComparator());
}
