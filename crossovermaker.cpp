#include "crossovermaker.h"
#include "randomnumgenerator.h"

CrossoverMaker::CrossoverMaker()
{

}

std::vector<Individual> CrossoverMaker::single_point_crossover(const Individual &lhs_parent, const Individual &rhs_parent)
{
    std::vector<Individual> children{};

    const int chromosome_length {lhs_parent.get_chromosome_length()};

    Individual child_a(chromosome_length);
    Individual child_b(chromosome_length);

    int random_pivot { RandomNumGenerator::get_real_between(0, chromosome_length -1) };

    for(int i {0}; i < chromosome_length; i++)
    {
        if(i <= random_pivot)
        {
            child_a.set_gene(i, lhs_parent.get_gene(i));
            child_b.set_gene(i, rhs_parent.get_gene(i));
        }
        else
        {
            child_a.set_gene(i, rhs_parent.get_gene(i));
            child_b.set_gene(i, lhs_parent.get_gene(i));
        }
    }

    children.emplace_back(child_a);
    children.emplace_back(child_b);

    return children;
}

std::vector<Individual> CrossoverMaker::two_points_crossover(const Individual &lhs_parent, const Individual &rhs_parent)
{

}

std::vector<Individual> CrossoverMaker::uniform_crossover(const Individual &lhs_parent, const Individual &rhs_parent)
{

}
