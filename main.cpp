#include <iostream>
#include "geneticsolver.h"
#include "randomnumgenerator.h"

using namespace std;

int main()
{

    int searched_sum, population_size, digits_number;

    std::cout << "*** BASIC GENETIC ALGORITHM PROBLEM SOLVING BY A.C ***" << std::endl << std::endl;
    std::cout << "The goal of this GA is to find numbers which the sum \nof all its digits give a defined number." << std::endl;
    std::cout << "Solutions are represented as common numbers in base 10." << std::endl;
    std::cout << std::endl;
    std::cout << "___PLEASE SET BASIC PARAMETERS___" << std::endl << std::endl;
    std::cout << "Searched sum value : ";
    std::cin >> searched_sum;
    std::cout << "Length of solutions in digits : ";
    std::cin >> digits_number;

    std::cout << std::endl;
    std::cout << "___PLEASE SET ALGORITHM PARAMETERS (CRUCIAL)___" << std::endl;
    std::cout << std::endl;

    double mutate_probability, max_mutate, min_mutate;
    int generations_number;

    std::cout << "Number of individuals in population : ";
    std::cin >> population_size;
    std::cout << "Mutate probability per individual : ";
    std::cin >> mutate_probability;
    std::cout << "Minimum variation of gene during mutation : ";
    std::cin >> min_mutate;
    std::cout << "Maximum variation of gene during mutation : ";
    std::cin >> max_mutate;
    std::cout << "Number of generations : ";
    std::cin >> generations_number;

    std::cout << std::endl << "PROCESSING...";


    GeneticSolver solver {};


    solver.set_digits_number(digits_number);
    solver.set_population_size(population_size);
    solver.set_searched_sum(searched_sum);
    solver.set_mutate_probability(mutate_probability);
    solver.set_min_mutate_variation(min_mutate);
    solver.set_max_mutate_variation(max_mutate);

    for(int i {0}; i < generations_number; i++)
    {
        solver.go_to_next_generation();
    }

    std::cout << "DONE !" << std::endl << std::endl;

    solver.describe();

    return 0;
}
