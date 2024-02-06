cmake_minimum_required(VERSION 3.17)

project(proposer_tests VERSION 0.1 LANGUAGES CXX)

add_executable(tests "proposertest.cpp" "doctest.h") 

target_compile_features(tests PUBLIC cxx_std_17)
