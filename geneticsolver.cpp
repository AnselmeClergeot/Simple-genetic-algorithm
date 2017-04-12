#include "geneticsolver.h"
#include "randomnumgenerator.h"
#include <cassert>
#include <algorithm>

GeneticSolver::GeneticSolver() :
    m_population_size(10),
    m_digits_number(6),
    m_searched_sum(42),
    m_number_parents_selected(2),
    m_generation_number(100),
    m_mutate_probability(0.05),
    m_crossover_mode(CrossoverMode::SinglePoint),
    m_end_condition(EndCondition::MaxIteration),
    m_start_population(StartPopulation::Random),
    m_population(),
    m_fitness_calculator(&m_population),
    m_current_generation(0),
    m_parents(),
    m_children(),
    m_min_mutate_variation(0.01),
    m_max_mutate_variation(0.05)

{
    RandomNumGenerator::initialize();
}

void GeneticSolver::set_population_size(const int size)
{
    m_population_size = size;

    for(int i {0}; i < size; i++)
    {
        m_population.emplace_back(Individual(m_digits_number));
    }
}

void GeneticSolver::set_digits_number(const int number)
{
    m_digits_number = number;
}

void GeneticSolver::set_searched_sum(const int sum)
{
    m_searched_sum = sum;
    m_fitness_calculator.set_searched_sum(sum);
}

void GeneticSolver::set_number_of_parents_selected(const int number)
{
    m_number_parents_selected = number;
}

void GeneticSolver::set_generation_number(const int number)
{
    m_generation_number = number;
}

void GeneticSolver::set_mutate_probability(const double probability)
{
    m_mutate_probability = probability;
}

void GeneticSolver::set_crossover_mode(const CrossoverMode mode)
{
    m_crossover_mode = mode;
}

void GeneticSolver::set_end_condition(const EndCondition condition)
{
    m_end_condition = condition;
}

void GeneticSolver::set_start_population(const StartPopulation start)
{
    m_start_population = start;
}

void GeneticSolver::set_min_mutate_variation(const int variation)
{
    m_min_mutate_variation = variation;
}

void GeneticSolver::set_max_mutate_variation(const int variation)
{
    m_max_mutate_variation = variation;
}

int GeneticSolver::get_min_mutate_variation() const
{
    return m_min_mutate_variation;
}

int GeneticSolver::get_max_mutate_variation() const
{
    return m_max_mutate_variation;
}

void GeneticSolver::go_to_next_generation()
{
    m_fitness_calculator.calculate_all_fitnesses();

    std::sort(m_population.begin(), m_population.end(), IndividualComparator());

    select_parents();
    mate_parents();
    insert_children();
    do_mutations();

    m_current_generation++;
    m_fitness_calculator.calculate_all_fitnesses();
}

void GeneticSolver::solve_entirely()
{
    while(!m_population[0].is_operational())
        go_to_next_generation();
    std::cout << "Needed " << m_current_generation << " generations to get the best solution possible.";
}

void GeneticSolver::select_parents()
{
    int sum_of_fitnesses {0};

    for(Individual indiv : m_population)
        sum_of_fitnesses += indiv.get_fitness();

    for(int i {0}; i < m_number_parents_selected; i++)
    {
        int roulette_value { RandomNumGenerator::get_real_between(0, sum_of_fitnesses)};
        int index_of_indiv_selected {0};
        int current_roulette_value {m_population[0].get_fitness()};

        while(current_roulette_value < roulette_value)
        {
            current_roulette_value += m_population[index_of_indiv_selected].get_fitness();
            index_of_indiv_selected++;
        }

        m_parents.emplace_back(m_population[index_of_indiv_selected]);
    }
}

void GeneticSolver::mate_parents()
{
    for(int i {0}; i < m_number_parents_selected; i++)
    {
        for(int j {i+1}; j < m_number_parents_selected; j++)
        {
            std::vector<Individual> children;

            switch (m_crossover_mode) {
            case CrossoverMode::SinglePoint:
                children = CrossoverMaker::single_point_crossover(m_parents[i], m_parents[j]);
                break;

            case CrossoverMode::TwoPoint:
                children = CrossoverMaker::two_points_crossover(m_parents[i], m_parents[j]);
                break;

            case CrossoverMode::Uniform:
                children = CrossoverMaker::uniform_crossover(m_parents[i], m_parents[j]);
                break;
            default:
                break;
            }

            for(Individual indiv : children)
                m_children.emplace_back(indiv);
        }
    }

    m_parents.clear();
}

void GeneticSolver::insert_children()
{
    for(int i {0}; i < m_children.size(); i++)
    {
        m_population[m_population_size - 1 - i] = m_children[i];
    }

    m_children.clear();
}

void GeneticSolver::do_mutations()
{
    for(Individual &indiv : m_population)
    {
        const int gene_pos {RandomNumGenerator::get_real_between(0, indiv.get_chromosome_length())};

        if(RandomNumGenerator::get_real_between(0, 1) < m_mutate_probability)
        {
            const int gene_variation {RandomNumGenerator::get_real_between(m_min_mutate_variation, m_max_mutate_variation)};
            indiv.set_gene(gene_pos, indiv.get_gene(gene_pos) + gene_variation);
        }
    }
}

std::vector<Individual> GeneticSolver::get_population() const
{
    return m_population;
}

Individual GeneticSolver::get_best_individual()
{
    assert(!m_population.empty());

    std::sort(m_population.begin(), m_population.end(), IndividualComparator());

    return m_population[0];
}

int GeneticSolver::get_population_size() const
{
    return m_population_size;
}

int GeneticSolver::get_digits_number() const
{
    return m_digits_number;
}

int GeneticSolver::get_searched_sum() const
{
    return m_searched_sum;
}

int GeneticSolver::get_number_of_parents_selected() const
{
    return m_number_parents_selected;
}

int GeneticSolver::get_generation_number() const
{
    return m_generation_number;
}

double GeneticSolver::get_mutate_probability() const
{
    return m_mutate_probability;
}

CrossoverMode GeneticSolver::get_crossover_mode() const
{
    return m_crossover_mode;
}
EndCondition GeneticSolver::get_end_condition() const
{
    return m_end_condition;
}

StartPopulation GeneticSolver::get_start_population() const
{
    return m_start_population;
}

void GeneticSolver::describe()
{
    std::sort(m_population.begin(), m_population.end(), IndividualComparator());
    std::cout << "Here are all individuals of the population, from best to worst\n(note some can be equals) :" << std::endl;

    for(const Individual indiv : m_population)
        std::cout << indiv << std::endl;
}
