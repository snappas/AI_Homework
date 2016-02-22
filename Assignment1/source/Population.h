/*
 * Ryan Wedge, 0876437
 * Jiang Li, 1234621
*/
#ifndef PROJECT_GENERATEPOPULATION_H
#define PROJECT_GENERATEPOPULATION_H
#include <vector>
#include <deque>
#include <string>

using namespace std;

typedef vector<bool> Chromosome;
typedef deque<Chromosome> PopulationContainer;

class Population {
public:
    Population() {}
    ~Population(){}
    bool generate(size_t populationSize, size_t chromosomeLength);
    bool generate(size_t populationSize, size_t chromosomeLength, string seedValue);
    PopulationContainer &get();
    void set(PopulationContainer _population);
    Chromosome selectFrontParent();
    Chromosome selectBackParent();
    bool insertOffspring(vector<Chromosome> offspring);
    bool checkForGoal();

private:
    PopulationContainer population;



};


#endif //PROJECT_GENERATEPOPULATION_H
