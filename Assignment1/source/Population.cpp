
#include "Population.h"
#include <random>
#include <iostream>

using namespace std;

/*
 * Generate a population of random bits using a specific seed
 * Parameters: populationSize, chromosomeLength, seed value
 * Return: boolean
 */
bool Population::generate(size_t populationSize, size_t chromosomeLength, string seedValue) {
    seed_seq seed(seedValue.begin(), seedValue.end());
    mt19937 gen(seed);
    bernoulli_distribution dist; //Bernoulli distribution of type bool

    for(size_t i = 0; i < populationSize; i++){
        Chromosome chromosome;
        chromosome.reserve(chromosomeLength);

        for(size_t j = 0; j<chromosomeLength; j++){
            chromosome.push_back(dist(gen)); ///generate a random bool
        }
        population.push_back(chromosome);
    }

    return true;
}

/*
 * Generate a population of random bits using a random seed
 * Parameters: populationSize, chromosomeLength
 * Return: boolean
 */
bool Population::generate(size_t populationSize, size_t chromosomeLength) {
    random_device rd;
    mt19937 gen(rd());
    bernoulli_distribution dist; //Bernoulli distribution of type bool

    for (size_t i = 0; i < populationSize; i++) {
        Chromosome chromosome;
        chromosome.reserve(chromosomeLength);

        for (size_t j = 0; j < chromosomeLength; j++) {
            chromosome.push_back(dist(gen)); ///generate a random bool
        }
        population.push_back(chromosome);
    }

    return true;
}

/*
 * Get the population container
 * Return: Population container
 */
PopulationContainer &Population::get() {
    return population;
}

/*
 * Get the front element of the population container and remove it
 * Return: Population's first chromosome
 */
Chromosome Population::selectFrontParent() {
    Chromosome parent;
    parent = population.front();
    population.pop_front();
    return parent;
}

/*
 * Get the back element of the population container and remove it
 * Return: Population's last chromosome
 */
Chromosome Population::selectBackParent() {
    Chromosome parent;
    parent = population.back();
    population.pop_back();
    return parent;
}

/*
 * Insert a vector of chromosomes into the population
 * Return: boolean
 */
bool Population::insertOffspring(vector<Chromosome> offspring) {
    while (!offspring.empty()) {
        population.push_back(offspring.back());
        offspring.pop_back();
    }
    return true;
}

/*
 * Check if the goal '1111111111' was found in the population
 * Return: boolean
 */
bool Population::checkForGoal() {
    for (Chromosome chromosome : population) {
        int i = 0;
        for (bool bit: chromosome) {
            if (!bit) {
                break;
            } else {
                i++;
            }
            if (i == 10) {
                return true;
            }
        }
    }
    return false;
}

/*
 * Reassign the population to a different vector of chromosomes
 * Return: nothing
 */
void Population::set(PopulationContainer _population) {
    population = _population;
}
