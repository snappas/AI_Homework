/*
 * Ryan Wedge, 0876437
 * Jiang Li, 1234621
*/
#include <iostream>
#include <deque>
#include <sstream>
#include "Population.h"
#include "GeneticAlgorithm.h"

using namespace std;

void print_population(deque<vector<bool>> population);

int main(int argc, char **argv){

    size_t chromosomePopulationSize = 20; //Size of the population
    size_t chromosomeLength = 10; //Length of each chromosome
    double percentCrossOver = 0.0; //Percent of population used for crossover
    vector<bool> bitmask{1, 1, 1, 1, 1, 0, 0, 0, 0, 0}; //Bitmask used for crossover

    //Integer total of chromosomes to use for crossover each generation
    int crossOverTotal = (int) (percentCrossOver * chromosomePopulationSize);
    cout << "Crossover " << crossOverTotal << " chromosomes each generation" << endl;

    Population population;
    //Initial population generated randomly with a seed for same initial population
    population.generate(chromosomePopulationSize, chromosomeLength, "Homework1");

    cout << "Initial population: " << endl;
    print_population(population.get());

    int g = 1;
    //Perform crossover and mutation until the goal is reached
    while (!population.checkForGoal()) {
        //Perform the crossover 'crossOverTotal / 2' times since two chromosomes are used each time
        for (int i = 0; i < crossOverTotal / 2; i++) {
            //Produce two offspring from two parents in single_crossover
            vector<Chromosome> offspring = GeneticAlgorithm::single_crossover(population.selectFrontParent(),
                                                                              population.selectBackParent(),
                                                                              bitmask);
            //Insert the two offspring into the population
            population.insertOffspring(offspring);
        }
        g++;
        cout << "Generation " << g << " After Crossover:" << endl;
        print_population(population.get());
        if (population.checkForGoal()) { //Check for goal after crossover
            break;
        }
        //Perform the mutation to generate a new population and use it
        population.set(GeneticAlgorithm::mutateRandom(population.get()));
        cout << "Generation " << g << " After Mutation:" << endl;
        print_population(population.get());
    }
    cout << "Last generation: " << g << endl;

    return 0;
}

void print_population(PopulationContainer population) {
    int i = 1;
    //Output each chromosome from the population
    for (Chromosome chromosome : population) {
        ostringstream populationLine;
        populationLine << i << ":\t";
        for (bool bit : chromosome) {
            populationLine << bit;
        }
        //Output the fitness value for each chromosome
        populationLine << "\t Fitness: " << GeneticAlgorithm::fitness(chromosome) << '\n';
        i++;
        cout << populationLine.str();
    }
}