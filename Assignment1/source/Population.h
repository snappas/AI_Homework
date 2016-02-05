
#ifndef PROJECT_GENERATEPOPULATION_H
#define PROJECT_GENERATEPOPULATION_H
#include <vector>
#include <deque>

using namespace std;
class Population {
public:
    Population() {}
    ~Population(){}
    bool generate(size_t populationSize, size_t chromosomeLength);

    deque<vector<bool>> &get();

    void set(deque<vector<bool>> _population);

    vector<bool> selectFrontParent();

    vector<bool> selectBackParent();

    bool insertFamily(vector<vector<bool>> family);

    bool checkForGoal();

private:
    deque<vector<bool>> population;



};


#endif //PROJECT_GENERATEPOPULATION_H
