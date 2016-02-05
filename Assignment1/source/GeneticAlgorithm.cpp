

#include "GeneticAlgorithm.h"
#include <random>

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
    vector<vector<bool>> family;
    family.reserve(4); //2 offspring + 2 parents
    for (int child = 0; child < 2; child++) {
        vector<bool> offspring;
        offspring.reserve(10); //10 bits per chromosome
        for (int i = 0; i < mask.size(); i++) {
            if (mask[i]) { //take the bits where bitmask is 1 from the 1st parent
                offspring.push_back(mother[i]);
            } else { //take the bits where the bitmask is 0 from the 2nd parent
                offspring.push_back(father[i]);
            }
        }
        mask.flip(); //flip the bitmask for next offspring
        family.push_back(offspring);
    }
    family.push_back(mother);
    family.push_back(father);

    return family;
}

deque<vector<bool>> GeneticAlgorithm::mutateRandom(deque<vector<bool>> population) {
    random_device rd; //random number generator using hardware entropy
    mt19937 gen(rd()); //Mersenne Twister random number engine seeded with random device
    uniform_int_distribution<int> populationDistribution(0, (int) (population.size() - 1));
    uniform_int_distribution<int> bitDistribution(0, 9);
    int selectedChromosome = populationDistribution(gen);
    int selectedBit = bitDistribution(gen);

    vector<bool> mutateChromosome = population[selectedChromosome];
    bool mutateBit = mutateChromosome[selectedBit];

    if (mutateBit) {
        mutateBit = 0;
    } else {
        mutateBit = 1;
    }

    mutateChromosome[selectedBit] = mutateBit;

    population[selectedChromosome] = mutateChromosome;

    return population;
}