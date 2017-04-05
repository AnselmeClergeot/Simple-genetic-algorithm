#include "geneticsolver.h"

GeneticSolver::GeneticSolver() :
    m_population_size(10),
    m_digits_number(6),
    m_searched_sum(42),
    m_number_parents_selected(2),
    m_generation_number(100),
    m_mutate_probability(0.05),
    m_crossover_mode(CrossoverMode::SinglePoint),
    m_end_condition(EndCondition::MaxIteration),
    m_start_population(StartPopulation::Random)

{}

void GeneticSolver::set_population_size(const int size)
{
    m_population_size = size;
}

void GeneticSolver::set_digits_number(const int number)
{
    m_digits_number = number;
}

void GeneticSolver::set_searched_sum(const int sum)
{
    m_searched_sum = sum;
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

void GeneticSolver::set_generation_mode(const GenerationMode mode)
{
    m_generation_mode = mode;
}

void GeneticSolver::start_solving()
{

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

GenerationMode GeneticSolver::get_generation_mode() const
{
    return m_generation_mode;
}
