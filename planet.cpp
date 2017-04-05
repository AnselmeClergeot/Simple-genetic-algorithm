#include "planet.h"
#include "randomgenerators.h"
#include "crossovers.h"
#include <algorithm>
#include <array>
#include <cassert>

Planet::Planet(const int individuals_number, const int chromosome_length, const int wanted_value) : m_individuals(), m_calculator(wanted_value), m_selected_to_mate(), m_new_individuals()
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
    double sum_of_fitnesses { 0 };

    for(Individual indiv : m_individuals)
    {
        sum_of_fitnesses += indiv.get_fitness();
    }

    for(int i = 0; i < 2; i++)
    {
        double selected_fitness { RandomGenerators::real_between(0, sum_of_fitnesses) };

        double current_sum {m_individuals[0].get_fitness()};
        int selected_index {0};

        while(current_sum < selected_fitness)
        {
            current_sum += m_individuals[selected_index].get_fitness();
            selected_index++;
        }

        assert(selected_index < m_individuals.size());

        m_selected_to_mate.push_back(m_individuals[selected_index]);
    }
}

void Planet::mate_bests()
{
    for(unsigned int i = 0; i < m_selected_to_mate.size(); i++)
    {
        for(unsigned int j = i + 1; j < m_selected_to_mate.size(); j++)
        {
            std::vector<Individual> children_produced(Crossovers::get_children(m_selected_to_mate[i], m_selected_to_mate[j]));

            for(Individual indiv : children_produced)
            {
                m_new_individuals.push_back(indiv);
            }
        }
    }

    m_selected_to_mate.clear();
}

void Planet::insert_children()
{
    for(int i {0}; i < m_new_individuals.size(); i++)
    {
        assert(m_individuals.size()-1-i >= 0);

        m_individuals[m_individuals.size()-1-i] = m_new_individuals[i];
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
