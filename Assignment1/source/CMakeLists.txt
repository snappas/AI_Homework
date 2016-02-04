cmake_minimum_required (VERSION 2.6)
set(SOURCE ${SOURCE}
        main.cpp
        Population.cpp
        Population.h GeneticAlgorithm.cpp GeneticAlgorithm.h)

add_definitions(-std=c++11)

add_executable(Assignment1 ${SOURCE})