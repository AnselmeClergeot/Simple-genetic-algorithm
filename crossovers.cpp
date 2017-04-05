#include "crossovers.h"
#include "randomgenerators.h"

Crossovers::Crossovers()
{

}

std::vector<Individual> Crossovers::get_children(const Individual &lhs, const Individual &rhs)
{
    std::vector<Individual> children;

    const int chromosome_length {lhs.get_chromosome_length()};

    Individual child_a(chromosome_length);
    Individual child_b(chromosome_length);

    int random_pivot { RandomGenerators::real_between(0, chromosome_length -1) };

    for(int i {0}; i < chromosome_length; i++)
    {
        if(i <= random_pivot)
        {
            child_a.set_gene(i, lhs.get_gene(i));
            child_b.set_gene(i, rhs.get_gene(i));
        }
        else
        {
            child_a.set_gene(i, rhs.get_gene(i));
            child_b.set_gene(i, lhs.get_gene(i));
        }
    }

    children.emplace_back(child_a);
    children.emplace_back(child_b);

    return children;
}
