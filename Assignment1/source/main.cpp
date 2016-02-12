
#include <iostream>
#include <deque>
#include <sstream>
#include "Population.h"
#include "GeneticAlgorithm.h"

using namespace std;

void print_population(deque<vector<bool>> population);

int main(int argc, char **argv){

    size_t chromosomePopulationSize = 20;
    size_t chromosomeLength = 10;
    double percentCrossOver = 0.7;
    vector<bool> bitmask{1, 1, 1, 1, 1, 0, 0, 0, 0, 0};

    int crossOverTotal = (int) (percentCrossOver * chromosomePopulationSize);
    cout << "Crossover " << crossOverTotal << " chromosomes each generation" << endl;

    Population population;
    population.generate(chromosomePopulationSize, chromosomeLength, "Homework1");

    cout << "Initial population: " << endl;
    print_population(population.get());

    int g = 1;
    while (!population.checkForGoal()) {
        for (int i = 0; i < crossOverTotal / 2; i++) {
            vector<Chromosome> offspring = GeneticAlgorithm::single_crossover(population.selectFrontParent(),
                                                                              population.selectBackParent(),
                                                                              bitmask);
            population.insertOffspring(offspring);
        }
        g++;
        cout << "Generation " << g << " After Crossover:" << endl;
        print_population(population.get());
        if(population.checkForGoal()){
            break;
        }
        population.set(GeneticAlgorithm::mutateRandom(population.get()));
        cout << "Generation " << g << " After Mutation:" << endl;
        print_population(population.get());
    }
    cout << "Last generation: " << g << endl;

    return 0;
}

void print_population(PopulationContainer population) {
    int i = 1;

    for (Chromosome chromosome : population) {
        ostringstream populationLine;
        populationLine << i << ":\t";
        for (bool bit : chromosome) {
            populationLine << bit;
        }
        populationLine << "\t Fitness: " << GeneticAlgorithm::fitness(chromosome) << '\n';
        i++;
        cout << populationLine.str();
    }
}