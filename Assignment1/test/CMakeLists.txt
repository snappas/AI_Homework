cmake_minimum_required(VERSION 2.6)

add_definitions(-std=c++11)

add_executable(Population_Test Population_Test.cpp)
target_link_libraries(Population_Test LINK_PUBLIC libGeneticAlgorithm)

add_executable(GeneticAlgorithm_Test GeneticAlgorithm_Test.cpp)
target_link_libraries(GeneticAlgorithm_Test LINK_PUBLIC libGeneticAlgorithm)