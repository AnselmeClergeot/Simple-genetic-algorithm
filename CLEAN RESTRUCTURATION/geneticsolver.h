#ifndef GENETICSOLVER_H
#define GENETICSOLVER_H

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

enum GenerationMode
{
    Describe, Silence
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
        void set_generation_mode(const GenerationMode mode);

        int get_population_size() const;
        int get_digits_number() const;
        int get_searched_sum() const;
        int get_number_of_parents_selected() const;
        int get_generation_number() const;
        double get_mutate_probability() const;
        CrossoverMode get_crossover_mode() const;
        EndCondition get_end_condition() const;
        StartPopulation get_start_population() const;
        GenerationMode get_generation_mode() const;

        void start_solving();



    private:
        int m_population_size, m_digits_number, m_searched_sum, m_number_parents_selected, m_generation_number;
        double m_mutate_probability;

        CrossoverMode m_crossover_mode;
        EndCondition m_end_condition;
        StartPopulation m_start_population;
        GenerationMode m_generation_mode;

};

#endif // GENETICSOLVER_H
