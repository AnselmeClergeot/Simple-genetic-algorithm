#ifndef RANDOMNUMGENERATOR_H
#define RANDOMNUMGENERATOR_H


class RandomNumGenerator
{
public:
    RandomNumGenerator();
    static double get_real_between(const double taken_min, const double taken_max);
    static void initialize();
};

#endif // RANDOMNUMGENERATOR_H
