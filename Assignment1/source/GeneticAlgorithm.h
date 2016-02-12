
#ifndef PROJECT_GENETICALGORITHM_H
#define PROJECT_GENETICALGORITHM_H
#include <vector>
#include <deque>

using namespace std;

typedef vector<bool> Chromosome;
typedef deque<Chromosome> PopulationContainer;

class GeneticAlgorithm {
public:
    GeneticAlgorithm() {}
    ~GeneticAlgorithm() {}

    static int fitness(Chromosome chromosome);

    static vector<Chromosome> single_crossover(Chromosome mother, Chromosome father, vector<bool> bitmask);

    static PopulationContainer mutateRandom(PopulationContainer population);
};


#endif ///PROJECT_GENETICALGORITHM_H
