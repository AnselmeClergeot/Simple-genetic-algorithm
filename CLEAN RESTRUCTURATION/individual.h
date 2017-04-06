#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>
#include <iostream>

class Individual
{
public:
    Individual(const unsigned int chromosome_length);
    Individual(const std::vector<unsigned short> &genes);

    unsigned int get_chromosome_length() const;
    double get_fitness() const;
    bool is_operational() const;

    void set_operational(const bool operational);

    friend std::ostream &operator<<(std::ostream &stream, const Individual &indiv);

private:
    unsigned int m_chromosome_length;
    std::vector<unsigned short> m_genes;
    double m_fitness;
    bool m_operational;

};

#endif // INDIVIDUAL_H
