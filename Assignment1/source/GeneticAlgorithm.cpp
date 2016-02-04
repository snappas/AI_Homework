

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
