
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
    for (auto chromosome : chromosomes) {
        cout << i << ":\t";
        for (bool bit : chromosome) {
            cout << bit;
        }
        cout << "\t Fitness: " << geneticAlgorithm.fitness(chromosome);
        cout << endl;
        i++;
    }

    return 0;
}