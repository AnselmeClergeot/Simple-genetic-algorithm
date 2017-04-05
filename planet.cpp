#include "planet.h"
#include "randomgenerators.h"
#include <algorithm>
#include <array>

Planet::Planet(const int individuals_number, const int chromosome_length, const int wanted_value) : m_individuals(), m_calculator(wanted_value), m_selected_to_mate(), m_new_individuals
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
    for(int i = 0; i < m_selected_to_mate; i++)
    {
        for(int j = i +1; j < m_selected_to_mate.size(); j++)
        {
            std::arrau
        }
    }

    m_selected_to_mate.clear();
}

void Planet::insert_children()
{
    for(int i {m_individuals.size() - 1}; i >= m_individuals.size() - 1 - m_new_individuals.size(); i--)
    {
        m_individuals[i] = m_new_individuals[i];
    }

    m_new_individuals.clear();
}

void Planet::mutate()
{
    for(Individual &indiv : m_individuals)
    {
        indiv.mutate(0.05, 2);
    }
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
