
#ifndef PROJECT_GENERATEPOPULATION_H
#define PROJECT_GENERATEPOPULATION_H
#include <vector>

using namespace std;
class Population {
public:
    Population() {}
    ~Population(){}
    bool generate(size_t populationSize, size_t chromosomeLength);
    vector<vector<bool>> &get();

private:
    vector<vector<bool>> population;

};


#endif //PROJECT_GENERATEPOPULATION_H
