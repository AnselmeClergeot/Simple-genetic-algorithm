#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>
#include <iostream>

class Individual
{
    friend class FitnessCalculator;
    friend class IndividualComparator;

public:
    Individual(const unsigned int chromosome_length);
    Individual(const std::vector<unsigned short> &genes);

    unsigned int get_chromosome_length() const;
    double get_fitness() const;
    bool is_operational() const;
    unsigned short get_gene(const unsigned int pos) const;

    void set_operational(const bool operational);
    void set_fitness(const double fitness);

    void set_gene(const unsigned int pos, const unsigned short gene);

    friend std::ostream &operator<<(std::ostream &stream, const Individual &indiv);



private:
    unsigned int m_chromosome_length;
    std::vector<unsigned short> m_genes;
    double m_fitness;
    bool m_operational;
};

class IndividualComparator
{
public:
    bool operator()(const Individual &lhs, const Individual &rhs);
};



#endif // INDIVIDUAL_H
