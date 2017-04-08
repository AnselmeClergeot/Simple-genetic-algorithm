#ifndef GENETICSOLVER_H
#define GENETICSOLVER_H
#include "individual.h"
#include "fitnesscalculator.h"
#include "crossovermaker.h"
#include <vector>

enum CrossoverMode
{
    SinglePoint, TwoPoint, Uniform
};

enum EndCondition
{
    MaxIteration, PerfectSolution
};

enum StartPopulation
{
    Random, Heuristic
};

class GeneticSolver
{
    public:
        GeneticSolver();

        void set_population_size(const int size);
        void set_digits_number(const int number);
        void set_searched_sum(const int sum);
        void set_number_of_parents_selected(const int number);
        void set_generation_number(const int number);
        void set_mutate_probability(const double probability);
        void set_crossover_mode(const CrossoverMode mode);
        void set_end_condition(const EndCondition condition);
        void set_start_population(const StartPopulation start);

        void set_min_mutate_variation(const int variation);
        void set_max_mutate_variation(const int variation);
        int get_min_mutate_variation() const;
        int get_max_mutate_variation() const;

        int get_population_size() const;
        int get_digits_number() const;
        int get_searched_sum() const;
        int get_number_of_parents_selected() const;
        int get_generation_number() const;
        double get_mutate_probability() const;
        CrossoverMode get_crossover_mode() const;
        EndCondition get_end_condition() const;
        StartPopulation get_start_population() const;

        void go_to_next_generation();
        void solve_entirely();

        std::vector<Individual> get_population() const;
        Individual get_best_individual();

    private:
        int m_population_size, m_digits_number, m_searched_sum, m_number_parents_selected, m_generation_number;
        double m_mutate_probability;
        int m_min_mutate_variation, m_max_mutate_variation;

        CrossoverMode m_crossover_mode;
        EndCondition m_end_condition;
        StartPopulation m_start_population;

        FitnessCalculator m_fitness_calculator;

        std::vector<Individual> m_population;
        std::vector<Individual> m_parents;
        std::vector<Individual> m_children;

        void select_parents();
        void mate_parents();
        void insert_children();
        void do_mutations();

        unsigned int m_current_generation;

};

#endif // GENETICSOLVER_H
