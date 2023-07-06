/**
 * @file main.cpp
 * @author Dilesh Vallabh
 * @brief Compute answers to Project Euler problems.
 * @version 0.1
 * @date 2023-07-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <chrono>
#include <iostream>
#include <map>

#include "Algorithm_Functions.h"
#include "Euler_Problems.h"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        cout << "No arguments passed. Input problem ID." << endl;
        return 1;
    } else if (argc > 2) {
        cout << "Too many arguments passed. Input a singular problem ID."
             << endl;
        return 2;
    }

    const int problem_ID = int(*argv[1] - '0');

    const auto start = std::chrono::high_resolution_clock::now();

    switch (problem_ID) {
        case 1:
            cout << problem_1(1000) << endl;
            break;
        case 2:
            cout << problem_2(4e6) << endl;
            break;
        case 3:
            cout << problem_3(600851475143) << endl;
            break;
        case 4:
            cout << problem_4(100, 999) << endl;
            break;
        case 5:
            cout << problem_5(20) << endl;
            break;
        case 6:
            problem_6(100);
            break;
        case 7:
            problem_7(10001);
            break;
        default:
            cout << "Not implemented." << endl;
            break;
    }

    const auto end = std::chrono::high_resolution_clock::now();

    const auto run_time =
        std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Run time: " << run_time.count() << " \u00B5s" << endl;

    return 0;
}