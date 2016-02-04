
#include <iostream>
#include "Population.h"
#include "GeneticAlgorithm.h"

using namespace std;

int main(int argc, char **argv){

    Population population;
    population.generate(20, 10);
    vector<vector<bool>> chromosomes = population.get();

    GeneticAlgorithm geneticAlgorithm;

    int i = 1;
    for(auto c : chromosomes){
        cout << i << ":\t";
        for(bool bit : c){
            cout << bit;
        }
        cout << "\t Fitness: " << geneticAlgorithm.fitness(c);
        cout << endl;
        i++;
    }

    return 0;
}