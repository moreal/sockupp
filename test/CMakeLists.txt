cmake_minimum_required(VERSION 3.10.2)

#########################################
#           TEST CODE MAKELIST          #
#########################################

project(test)

# Include sockupp library

find_library(
        LIBSOCKUPP
        NAMES sockupp
        PATHS ./lib
        REQUIRED
)

target_include_directories(sockupp PRIVATE ${PROJECT_SOURCE_DIR}/src)

# Add test
add_executable(runTests
    tcpsocket.cc
)

target_link_libraries(runTests ${LIBSOCKUPP})

# Include gtest library
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#target_link_libraries(runTests gtest gtest_main)
