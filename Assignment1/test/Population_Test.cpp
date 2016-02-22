/*
 * Ryan Wedge, 0876437
 * Jiang Li, 1234621
*/
#include "Population.h"
#include <cassert>
#include <iostream>

using std::cout;
using std::endl;

void test_generate_population_size();

void test_generate_same_initial_population();

void test_generate_random_initial_population();

void test_generate_chromosome_length();

void test_check_for_goal();

void test_insert_offspring();

int main(int argc, char **argv) {
    test_generate_population_size();
    test_generate_chromosome_length();
    test_generate_same_initial_population();
    test_generate_random_initial_population();
    test_check_for_goal();
    test_insert_offspring();
    return 0;
}

void test_insert_offspring() {
    Chromosome child1{1, 1, 1, 1, 1, 0, 1, 1, 1, 1};
    Chromosome child2{1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
    vector<Chromosome> offspring{child1, child2};
    Population p;
    p.generate(1, 10);
    p.insertOffspring(offspring);
    cout << "Test: insert offspring: ";
    assert(p.get().size() == 3);
    cout << "Passed" << endl;
}

void test_check_for_goal() {
    Chromosome goal{1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    PopulationContainer container{goal};
    Population p;
    p.set(container);
    cout << "Test: check for goal: ";
    assert(p.checkForGoal());
    cout << "Passed" << endl;
}


void test_generate_random_initial_population() {
    Population p1, p2;
    p1.generate(1, 10);
    p2.generate(1, 10);
    cout << "Test: random initial population: ";
    assert(p1.selectFrontParent() != p2.selectFrontParent());
    cout << "Passed" << endl;
}

void test_generate_same_initial_population() {
    Population p1, p2;
    p1.generate(1, 10, "test");
    p2.generate(1, 10, "test");
    cout << "Test: same initial population: ";
    assert(p1.selectFrontParent() == p2.selectFrontParent());
    cout << "Passed" << endl;
}

void test_generate_population_size() {
    Population p;
    p.generate(1, 10);
    cout << "Test: population size: ";
    assert(p.get().size() == 1);
    cout << "Passed" << endl;
}

void test_generate_chromosome_length() {
    Population p;
    p.generate(1, 10);
    cout << "Test: chromosome length: ";
    assert(p.selectFrontParent().size() == 10);
    cout << "Passed" << endl;
}
