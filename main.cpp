#include <iostream>
#include "geneticsolver.h"
#include "randomnumgenerator.h"

using namespace std;

int main()
{
    int searched_sum, population_size {15}, digits_number;
    double mutate_probability {0.05}, max_mutate {2}, min_mutate {-2};
    int generations_number {5000}, parents_number{3}, crossover_mode{2};
    int end_condition {};

    std::cout << "*** BASIC GENETIC ALGORITHM PROBLEM SOLVING BY Anselme Clergeot ***" << std::endl << std::endl;
    std::cout << "The goal of this GA is to find a number which the sum \nof all its digits give a defined number." << std::endl;
    std::cout << "Solutions are represented as common numbers in base 10." << std::endl;
    std::cout << std::endl;
    std::cout << "___PLEASE SET BASIC PARAMETERS___" << std::endl << std::endl;
    std::cout << "Searched sum value : ";
    std::cin >> searched_sum;
    std::cout << "Length of solutions in digits : ";
    std::cin >> digits_number;
    std::cout << "End condition : generations number (0) or first perfect solution found (1) :  ";
    std::cin >> end_condition;

    if(end_condition == 0)
    {
        std::cout << "Number of generations : ";
        std::cin >> generations_number;
    }

    std::cout << std::endl << "Do you want to set internal parameters of the algorithm (y/n) ? \nIf you choose no, default parameters will be chosen. Note that \nthey might be inapropriate : ";

    std::string param {};

    std::cin >> param;

    if(param == "y")
    {
        std::cout << std::endl;
        std::cout << "___PLEASE SET ALGORITHM PARAMETERS (CRUCIAL)___" << std::endl;
        std::cout << std::endl;



        std::cout << "Number of individuals in population : ";
        std::cin >> population_size;
        std::cout << "Mutate probability per individual : ";
        std::cin >> mutate_probability;
        std::cout << "Minimum variation of gene during mutation : ";
        std::cin >> min_mutate;
        std::cout << "Maximum variation of gene during mutation : ";
        std::cin >> max_mutate;
        std::cout << "Number of parents selected each generation : ";
        std::cin >> parents_number;
        std::cout << "Crossover method (0 : single point, 1 : two points, 2 : uniform) : ";
        std::cin >> crossover_mode;
    }

    int display_mode {};
    std::cout << std::endl << "How to display solutions ? all population (0) or only best solution (1) : ";
    std::cin >> display_mode;

    std::cout << std::endl << "PROCESSING... CAN BE LONG...";


    GeneticSolver solver {};


    solver.set_digits_number(digits_number);
    solver.set_population_size(population_size);
    solver.set_searched_sum(searched_sum);
    solver.set_mutate_probability(mutate_probability);
    solver.set_min_mutate_variation(min_mutate);
    solver.set_max_mutate_variation(max_mutate);
    solver.set_number_of_parents_selected(parents_number);
    solver.set_crossover_mode(static_cast<CrossoverMode>(crossover_mode));

    if(end_condition == 0)
    {
        for(int i {0}; i < generations_number; i++)
        {
            solver.go_to_next_generation();
        }
    }
    else
    {

        solver.solve_entirely();
    }

        std::cout << " DONE !" << std::endl << std::endl;


    if(display_mode == 0)
    {
        solver.describe();
    }
    else
    {
        std::cout << solver.get_best_individual();
    }


    system("pause");
    return 0;
}
