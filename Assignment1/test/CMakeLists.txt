cmake_minimum_required(VERSION 2.6)
set(TEST_SOURCE ${TEST_SOURCE}
        random.cpp)

add_definitions(-std=c++11)
add_executable(Random_Test random.cpp random.cpp)