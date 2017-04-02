#ifndef PLANET_H
#define PLANET_H
#include <vector>
#include "individual.h"
#include "fitnesscalculator.h"

class Planet
{
public:
    Planet(const int individuals_number, const int chromosome_length, const int wanted_value);

    void calculate_fitnesses();
    void select_bests();
    void mate_bests();
    void insert_children();
    void mutate();
    void describe() const;


private:
    std::vector<Individual> m_individuals;
    FitnessCalculator m_calculator;

    void refresh_order();
};

#endif // PLANET_H
