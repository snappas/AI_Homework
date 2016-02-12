cmake_minimum_required (VERSION 2.6)
set(DRIVER ${DRIVER}
        main.cpp)
set(SOURCE ${SOURCE}
        Population.cpp
        Population.h
        GeneticAlgorithm.cpp
        GeneticAlgorithm.h)

add_definitions(-std=c++11)

add_executable(Assignment1 ${DRIVER} ${SOURCE})

add_library(libGeneticAlgorithm ${SOURCE})
target_include_directories(libGeneticAlgorithm PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})