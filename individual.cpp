#include "individual.h"
#include "randomgenerators.h"
#include <algorithm>

Individual::Individual(const int chromosome_length) : m_genes(chromosome_length), m_fitness(0)
{
    for(int i = 0; i < chromosome_length; i++)
    {
        m_genes[i] = RandomGenerators::real_between(0, 10);
    }
}

int Individual::get_gene(const int pos) const
{
    return m_genes[pos];
}

int Individual::get_chromosome_length() const
{
    return m_genes.size();
}

std::ostream &operator<<(std::ostream &stream, const Individual &debug)
{
    stream << "chromosome : ";
    for(int gene : debug.m_genes)
    {
        stream << gene;
    }

    stream << " | fitness : " << debug.m_fitness;
    return stream;
}

void Individual::set_fitness(const int value)
{
    m_fitness = value;
}

void Individual::mutate(const double probability, const int max_variation)
{

    if(RandomGenerators::real_between(0, 1) < probability)
    {
        int random_pos {RandomGenerators::real_between(0, m_genes.size()-1)};

        double random_variation {RandomGenerators::real_between(-max_variation, +max_variation)};

        m_genes[random_pos] += random_variation;
    }
}

int Individual::get_fitness() const
{
    return m_fitness;
}

bool IndividualComparator::operator()(const Individual &lhs, const Individual &rhs)
{
    return lhs.get_fitness() > rhs.get_fitness();
}
