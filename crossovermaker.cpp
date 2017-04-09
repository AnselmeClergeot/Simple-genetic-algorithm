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

    int random_pivot { RandomNumGenerator::get_real_between(0, chromosome_length) };

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
    std::vector<Individual> children {};
    Individual a(lhs_parent.get_chromosome_length());
    Individual b(lhs_parent.get_chromosome_length());

    int point_1 {RandomNumGenerator::get_real_between(0, lhs_parent.get_chromosome_length())};
    int point_2 {RandomNumGenerator::get_real_between(0, lhs_parent.get_chromosome_length())};

    int first_point(std::min(point_1, point_2));
    int last_point(std::max(point_1, point_2));

    int parent_selected(RandomNumGenerator::get_real_between(0, 2));

    for(int i {0}; i < lhs_parent.get_chromosome_length(); i++)
    {
        if(i >= first_point && i <= last_point)
        {
            if(parent_selected == 0)
            {
                a.set_gene(i, lhs_parent.get_gene(i));
                b.set_gene(i, rhs_parent.get_gene(i));
            }
            else
            {
                a.set_gene(i, rhs_parent.get_gene(i));
                b.set_gene(i, lhs_parent.get_gene(i));
            }
        }
        else
        {
            if(parent_selected == 1)
            {
                a.set_gene(i, lhs_parent.get_gene(i));
                b.set_gene(i, rhs_parent.get_gene(i));
            }
            else
            {
                a.set_gene(i, rhs_parent.get_gene(i));
                b.set_gene(i, lhs_parent.get_gene(i));
            }
        }
    }

    children.push_back(a);
    children.push_back(b);

    return children;

}

std::vector<Individual> CrossoverMaker::uniform_crossover(const Individual &lhs_parent, const Individual &rhs_parent)
{
    std::vector<Individual> children {};

    Individual a(lhs_parent.get_chromosome_length()), b(lhs_parent.get_chromosome_length());

    for(int i {0}; i < lhs_parent.get_chromosome_length(); i++)
    {
        int parent_selected {RandomNumGenerator::get_real_between(0, 2)};

        if(parent_selected == 0)
        {
            a.set_gene(i, lhs_parent.get_gene(i));
            b.set_gene(i, rhs_parent.get_gene(i));
        }
        else
        {
            a.set_gene(i, rhs_parent.get_gene(i));
            b.set_gene(i, lhs_parent.get_gene(i));
        }
    }

    children.push_back(a);
    children.push_back(b);

    return children;
}
