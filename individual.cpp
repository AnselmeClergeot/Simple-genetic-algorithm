#include "individual.h"
#include "randomnumgenerator.h"

Individual::Individual(const unsigned int chromosome_length) : m_chromosome_length(chromosome_length), m_fitness(), m_operational(), m_genes()
{
    for(int i {0}; i < chromosome_length; i++)
    {
        m_genes.push_back(RandomNumGenerator::get_real_between(0, 10));
    }
}

Individual::Individual(const std::vector<unsigned short> &genes) : m_chromosome_length(genes.size()), m_fitness(), m_operational(), m_genes(genes)
{

}

unsigned int Individual::get_chromosome_length() const
{
    return m_chromosome_length;
}

double Individual::get_fitness() const
{
    return m_fitness;
}

bool Individual::is_operational() const
{
    return m_operational;
}

void Individual::set_operational(const bool operational)
{
    m_operational = operational;
}

void Individual::set_fitness(const double fitness)
{
    m_fitness = fitness;
}

void Individual::set_gene(const unsigned int pos, const unsigned short gene)
{
    if(gene <= 9)
        m_genes[pos] = gene;
}

std::ostream &operator<<(std::ostream &stream, const Individual &indiv)
{
    stream << "CHROMOSOME : " << std::endl;

    for(unsigned short gene : indiv.m_genes)
        stream << gene;
    stream << std::endl;

    if(!indiv.m_operational)
        stream << "FITNESS : " << indiv.m_fitness << "/1000";
    else
        stream << "PERFECT SOLUTION";

    stream << std::endl;

    return stream;
}

unsigned short Individual::get_gene(const unsigned int pos) const
{
    return m_genes[pos];
}

bool IndividualComparator::operator ()(const Individual &lhs, const Individual &rhs)
{
    return lhs.m_fitness > rhs.m_fitness;
}
