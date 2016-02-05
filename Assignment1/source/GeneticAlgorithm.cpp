

#include "GeneticAlgorithm.h"

int GeneticAlgorithm::fitness(vector<bool> chromosome) {
    int fit = 0;
    for(bool n : chromosome){
        if(n){
            fit++; //count the number of 1's
        }
    }
    return fit;
}

vector<vector<bool>> GeneticAlgorithm::single_crossover(vector<bool> mother, vector<bool> father) {
    vector<bool> mask{1, 1, 1, 1, 1, 0, 0, 0, 0, 0}; //bitmask 5x1's, 5x0's
    vector<vector<bool>> children;
    children.reserve(2); //2 offspring
    for (int child = 0; child < 2; child++) {
        vector<bool> offspring;
        offspring.reserve(10);
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i]) { //take the bits where bitmask is 1 from the 1st parent
                offspring.push_back(mother[i]);
            } else { //take the bits where the bitmask is 0 from the 2nd parent
                offspring.push_back(father[i]);
            }
        }
        mask.flip(); //flip the bitmask for next offspring
        children.push_back(offspring);
    }
    return children;

}
