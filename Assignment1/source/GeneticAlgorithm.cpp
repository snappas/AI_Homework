/*
 * Ryan Wedge, 0876437
 * Jiang Li, 1234621
*/

#include "GeneticAlgorithm.h"
#include <random>

/*
 * Determine the fitness value of a chromosome
 * Return: the number of 1s counted
 */
int GeneticAlgorithm::fitness(Chromosome chromosome) {
    int fit = 0;
    for(bool n : chromosome){
        if(n){
            fit++; //count the number of 1's
        }
    }
    return fit;
}

/*
 * Perform single-crossover to produce two offspring given two parents and a bitmask
 * Parameters: parent1, parent2, bitmask
 * Return: two siblings produced from two parents
 */
vector<Chromosome> GeneticAlgorithm::single_crossover(Chromosome mother, Chromosome father, vector<bool> bitmask) {
    vector<Chromosome> siblings;
    for (int offspring = 0; offspring < 2; offspring++) {
        Chromosome child;

        for (int i = 0; i < bitmask.size(); i++) {
            if (bitmask[i]) {
                //take the bits where bitmask is 1 from the 1st parent
                child.push_back(mother[i]);
            } else {
                //take the bits where the bitmask is 0 from the 2nd parent
                child.push_back(father[i]);
            }
        }
        //flip the bitmask for the next child
        bitmask.flip();
        siblings.push_back(child);
    }

    return siblings;
}

/*
 * Select a random chromosome from the population, then select a random bit from the chromosome to flip
 * Return: New population with mutation applied
 */
PopulationContainer GeneticAlgorithm::mutateRandom(PopulationContainer population) {
    random_device rd; //random number generator using hardware entropy
    mt19937 gen(rd()); //Mersenne Twister random number engine seeded with random device
    uniform_int_distribution<int> populationDistribution(0, (int) (population.size() - 1));
    uniform_int_distribution<int> bitDistribution(0, 9);

    int populationRandomIndex = populationDistribution(gen);
    int mutationRandomIndex = bitDistribution(gen);

    Chromosome selectedChromosome = population[populationRandomIndex];
    bool selectedBit = selectedChromosome[mutationRandomIndex];

    selectedChromosome[mutationRandomIndex] = !selectedBit; //do the mutation

    population[populationRandomIndex] = selectedChromosome; //replace the original chromosome with the mutated one

    return population;
}