#include <iostream>
#include <random>


using namespace std;

void test_uniform_int(uniform_int_distribution<int> dist, mt19937 gen);

void test_bernoulli_dist(bernoulli_distribution dist, mt19937 gen);

int main(int argc, char **argv) {
    random_device rd; //random number generator using hardware entropy
    mt19937 gen(rd()); //Mersenne Twister random number engine seeded with random device
    uniform_int_distribution<int> populationDistribution(0, 19);
    uniform_int_distribution<int> bitDistribution(0, 9);
    bernoulli_distribution randomTrueFalse;

    std::cout << "uniform_int_distribution (0,19):" << std::endl;
    test_uniform_int(populationDistribution, gen);

    std::cout << "uniform_int_distribution (0,9):" << std::endl;
    test_uniform_int(bitDistribution, gen);

    test_bernoulli_dist(randomTrueFalse, gen);

    return 0;
}


void test_uniform_int(uniform_int_distribution<int> dist, mt19937 gen) {
    const unsigned int nrolls = 10000; // number of experiments
    const unsigned int nstars = 150;    // maximum number of stars to distribute

    int p[20] = {};

    for (unsigned int i = 0; i < nrolls; ++i) {
        int number = dist(gen);
        ++p[number];
    }


    for (int i = dist.min(); i <= dist.max(); ++i)
        std::cout << i << ": " << std::string(p[i] * nstars / nrolls, '*') << std::endl;

}


void test_bernoulli_dist(bernoulli_distribution dist, mt19937 gen) {
    const int nrolls = 10000;
    int count = 0;  // count number of trues

    for (int i = 0; i < nrolls; ++i) if (dist(gen)) ++count;

    std::cout << "bernoulli_distribution (0.5) x 10000:" << std::endl;
    std::cout << "true:  " << count << std::endl;
    std::cout << "false: " << nrolls - count << std::endl;
}
