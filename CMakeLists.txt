cmake_minimum_required(VERSION 3.26.4)
project(Project_Euler VERSION 0.1.0 LANGUAGES CXX)

include_directories(
    PRIVATE "include"
    PRIVATE "src"
)

add_library(Euler_Problems STATIC # avoid recompiling
    src/Euler_Problems.cpp
)

add_library(Numeric_Utilities STATIC # avoid recompiling
    src/Numeric_Utilities.cpp
)

add_library(Special_Functions STATIC # avoid recompiling
    src/Special_Functions.cpp
)

add_executable(
    ${PROJECT_NAME} src/main.cpp
)
target_link_libraries(${PROJECT_NAME}
    Euler_Problems
    Numeric_Utilities
    Special_Functions
)

#find_package(Eigen3 REQUIRED)

find_package(Boost 1.74 COMPONENTS unit_test_framework REQUIRED)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

target_compile_features(
    ${PROJECT_NAME} PRIVATE cxx_std_20
)

target_compile_options(
    ${PROJECT_NAME}  PRIVATE -Wall -Wextra -Wpedantic
)

add_executable(test_unit
    src/Algorithm_Functions.test.cpp
)
target_link_libraries(test_unit 
    Boost::unit_test_framework
    Euler_Problems
    Algorithm_Functions
)

include(CTest) 
enable_testing ()
add_test(
    NAME Palindrome
    COMMAND test_unit --run_test=palindrome
)
add_test(
    NAME "Logarithmic Integral"
    COMMAND test_unit --run_test=logarithmic_integral
)