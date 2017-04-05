#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>
#include <iostream>

class Individual
{
    public:
        Individual(const int chromosome_length);

        int get_gene(const int pos) const;
        int get_chromosome_length() const;

        void set_gene(const int pos, const int value);
        void set_fitness(const double value);
        double get_fitness() const;

        void mutate(const double probability, const int max_variation);

    private:
        std::vector<int> m_genes;
        double m_fitness;

    friend std::ostream &operator<<(std::ostream &stream, const Individual &debug);
};

class IndividualComparator
{
public :
    bool operator()(const Individual &lhs, const Individual &rhs);
};



#endif // INDIVIDUAL_H
