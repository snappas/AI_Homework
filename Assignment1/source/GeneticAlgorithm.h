
#ifndef PROJECT_GENETICALGORITHM_H
#define PROJECT_GENETICALGORITHM_H
#include <vector>

using namespace std;

class GeneticAlgorithm {
public:
    GeneticAlgorithm() {}
    ~GeneticAlgorithm() {}

    static int fitness(vector<bool> chromosome);

    static vector<vector<bool>> single_crossover(vector<bool> mother, vector<bool> father);
};


#endif //PROJECT_GENETICALGORITHM_H
