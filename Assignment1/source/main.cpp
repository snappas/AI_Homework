
#include <iostream>
#include <deque>
#include <sstream>
#include "Population.h"
#include "GeneticAlgorithm.h"

using namespace std;

void print_population(deque<vector<bool>> chromosomes);

int main(int argc, char **argv){

    size_t chromosomePopulation = 20;
    size_t chromosomeLength = 10;
    double percentCrossOver = 0.7;

    int crossOverTotal = (int) (percentCrossOver * chromosomePopulation);

    cout << "crossover total: " << crossOverTotal << endl;

    Population population;

    population.generate(chromosomePopulation, chromosomeLength);
    int g = 1;
    cout << "Initial population: " << endl;
    print_population(population.get());

    while (!population.checkForGoal()) {
        for (int i = 0; i < crossOverTotal / 2; i++) {
            vector<vector<bool>> family = GeneticAlgorithm::single_crossover(population.selectFrontParent(),
                                                                             population.selectBackParent());
            population.insertFamily(family);
        }
        g++;
        cout << "Generation " << g << " After Crossover:" << endl;
        print_population(population.get());
        population.set(GeneticAlgorithm::mutateRandom(population.get()));
        cout << "Generation " << g << " After Mutation:" << endl;
        print_population(population.get());
    }

    return 0;
}

void print_population(deque<vector<bool>> chromosomes) {
    int i = 1;

    for (vector<bool> &chromosome : chromosomes) {
        ostringstream populationLine;
        populationLine << i << ":\t";
        for (bool bit : chromosome) {
            populationLine << bit;
        }
        populationLine << "\t Fitness: " << GeneticAlgorithm::fitness(chromosome);
        populationLine << '\n';
        i++;
        cout << populationLine.str();
    }
}