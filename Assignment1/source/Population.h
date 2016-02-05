
#ifndef PROJECT_GENERATEPOPULATION_H
#define PROJECT_GENERATEPOPULATION_H
#include <vector>
#include <bits/stl_deque.h>

using namespace std;
class Population {
public:
    Population() {}
    ~Population(){}
    bool generate(size_t populationSize, size_t chromosomeLength);

    deque<vector<bool>> &get();

    vector<bool> selectParent();

    bool insertOffspring(vector<vector<bool>> offspring);

private:
    deque<vector<bool>> population;





};


#endif //PROJECT_GENERATEPOPULATION_H
