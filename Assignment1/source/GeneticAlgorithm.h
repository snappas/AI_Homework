
#ifndef PROJECT_GENETICALGORITHM_H
#define PROJECT_GENETICALGORITHM_H
#include <vector>

using namespace std;

class GeneticAlgorithm {
public:
    GeneticAlgorithm() {}
    ~GeneticAlgorithm() {}
    int fitness(vector<bool> chromosome);
};


#endif //PROJECT_GENETICALGORITHM_H
