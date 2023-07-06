cmake_minimum_required(VERSION 3.26.4)
project(Project_Euler VERSION 0.1.0 LANGUAGES CXX)

add_executable(
    ${PROJECT_NAME} src/main.cpp
    src/Euler_Problems.cpp
    src/Algorithm_Functions.cpp
    src/Algorithm_Functions.tcc
)

#find_package(Eigen3 REQUIRED)

find_package(Boost 1.74 COMPONENTS program_options REQUIRED)

target_link_libraries(${PROJECT_NAME} Boost::program_options)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE "include"
    PRIVATE "src"
)

target_compile_features(
    ${PROJECT_NAME} PRIVATE cxx_std_20
)

target_compile_options(
    ${PROJECT_NAME}  PRIVATE -Wall -Wextra -Wpedantic
)
