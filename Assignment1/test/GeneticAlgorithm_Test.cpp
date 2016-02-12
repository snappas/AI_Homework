#include "GeneticAlgorithm.h"
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

void test_fitness_function();

void test_single_crossover();

void test_mutate_random();

int main(int argc, char **argv) {
    test_fitness_function();
    test_single_crossover();
    test_mutate_random();
    return 0;
}

void test_mutate_random() {
    Chromosome c{0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    PopulationContainer pc{c};
    cout << "Test: mutate random: ";
    assert(GeneticAlgorithm::mutateRandom(pc) != pc);
    cout << "Passed" << endl;
}

void test_single_crossover() {
    Chromosome p1{1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    Chromosome p2{0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
    vector<bool> bitmask{1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    Chromosome c1{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    Chromosome c2{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    vector<Chromosome> offspring{c1, c2};
    cout << "Test: single crossover: ";
    assert(GeneticAlgorithm::single_crossover(p1, p2, bitmask) == offspring);
    cout << "Passed" << endl;


}

void test_fitness_function() {
    Chromosome c{0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
    cout << "Test: fitness function: ";
    assert(GeneticAlgorithm::fitness(c) == 5);
    cout << "Passed" << endl;
}