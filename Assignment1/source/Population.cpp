
#include "Population.h"
#include <random>
#include <iostream>

using namespace std;

bool Population::generate(size_t populationSize, size_t chromosomeLength) {

    string seedValue("test");
    seed_seq seed(seedValue.begin(), seedValue.end());
    mt19937 gen(seed);
    bernoulli_distribution dist; //Bernoulli distribution of type bool

    for(size_t i = 0; i < populationSize; i++){
        vector<bool> chromosome;
        chromosome.reserve(chromosomeLength);

        for(size_t j = 0; j<chromosomeLength; j++){
            chromosome.push_back(dist(gen)); ///generate a random bool

        }
        population.push_back(chromosome);
    }

    return true;
}

deque<vector<bool>> &Population::get() {
    return population;
}

vector<bool> Population::selectFrontParent() {
    vector<bool> parent;
    parent = population.front();
    population.pop_front();
    return parent;
}

vector<bool> Population::selectBackParent() {
    vector<bool> parent;
    parent = population.back();
    population.pop_back();
    return parent;
}

bool Population::insertFamily(vector<vector<bool>> family) {
    while (!family.empty()) {
        population.push_back(family.back());
        family.pop_back();
    }
    return true;
}

bool Population::checkForGoal() {
    for (vector<bool> chromosome : population) {
        int i = 0;
        for (bool bit: chromosome) {
            if (!bit) {
                break;
            } else {
                i++;
            }
            if (i == 10) {
                cout << "*********SUCCESS*********" << endl;
                return true;
            }
        }
    }
    return false;
}

void Population::set(deque<vector<bool>> _population) {
    population = _population;
}
