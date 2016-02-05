
#include <iostream>
#include <deque>
#include "Population.h"
#include "GeneticAlgorithm.h"

using namespace std;

void print_population(deque<vector<bool>> chromosomes);

int main(int argc, char **argv){

    size_t chromosomePopulation = 20;
    size_t chromosomeLength = 10;

    Population population;

    population.generate(chromosomePopulation, chromosomeLength);

    print_population(population.get());

    vector<vector<bool>> offspring = GeneticAlgorithm::single_crossover(population.selectParent(),
                                                                        population.selectParent());
    population.insertOffspring(offspring);

    print_population(population.get());

    return 0;
}

void print_population(deque<vector<bool>> chromosomes) {
    int i = 1;

    for (vector<bool> &chromosome : chromosomes) {

        cout << i << ":\t";
        for (bool bit : chromosome) {
            cout << bit;
        }
        cout << "\t Fitness: " << GeneticAlgorithm::fitness(chromosome);
        cout << endl;
        i++;
    }
}