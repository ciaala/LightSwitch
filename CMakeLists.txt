cmake_minimum_required(VERSION 3.9)
project(LightSwitch)

set(CMAKE_CXX_STANDARD 14)
add_subdirectory(googletest)


set(LIBRARY_FILES
        src/switch_lib.cpp
        src/switch_lib.hpp
        src/light_controller_interface.hpp
        src/light_scheduler.cpp
        src/time_service_interface.hpp
        )

add_library(switch_lib ${LIBRARY_FILES})
target_include_directories(switch_lib
        PUBLIC src
        )
set(GTEST_FILES
        test/main.cpp
        test/test_add.cpp
        test/light_scheduler.cpp
        )
add_executable(switch_test ${GTEST_FILES})
target_link_libraries(switch_test gtest gmock switch_lib)
target_include_directories(switch_test
        INTERFACE gtest
        INTERFACE gmock
        PUBLIC test
        PUBLIC src)
add_test(${GTEST_FILES} switch_test)