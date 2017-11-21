cmake_minimum_required(VERSION 3.9)
project(LightSwitch)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)


set(LIBRARY_FILES
        src/switch_lib.cpp
        test/main.cpp)

add_library(switch_lib ${LIBRARY_FILES})



set(GTEST_FILES
        test/main.cpp
        )
add_executable(test ${GTEST_FILES})
target_link_libraries(switch_test gtest gmock switch_lib)
target_include_directories(switch_test
        INTERFACE gtest
        INTERFACE gmock
        PUBLIC test/include
        PUBLIC src/include)
add_test(${GTEST_FILES} switch_test)