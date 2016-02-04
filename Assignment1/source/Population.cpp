
#include "Population.h"
#include <random>

using namespace std;

bool Population::generate(size_t populationSize, size_t chromosomeLength) {
    random_device rd; //random number generator using hardware entropy
    mt19937 gen(rd()); //Mersenne Twister random number engine seeded with random device
    bernoulli_distribution dist; //Bernoulli distribution of type bool

    for(size_t i = 0; i < populationSize; i++){
        vector<bool> chromosome;
        chromosome.reserve(chromosomeLength);

        for(size_t j = 0; j<chromosomeLength; j++){
            chromosome.push_back(dist(gen)); //generate a random bool

        }
        population.push_back(chromosome);
    }

    return true;
}

vector<vector<bool>> &Population::get() {
    return population;
}
