
#ifndef PROJECT_GENETICALGORITHM_H
#define PROJECT_GENETICALGORITHM_H
#include <vector>
#include <bits/stl_deque.h>

using namespace std;

class GeneticAlgorithm {
public:
    GeneticAlgorithm() {}
    ~GeneticAlgorithm() {}

    static int fitness(vector<bool> chromosome);

    static vector<vector<bool>> single_crossover(vector<bool> mother, vector<bool> father);

    static std::deque<vector<bool>> mutateRandom(std::deque<vector<bool>> population);
};


#endif //PROJECT_GENETICALGORITHM_H
