/**
 * @file Algorithm_Functions.cpp
 * @author Dilesh Vallabh
 * @brief Implementations of Algorithm_Functions.
 * @version 0.1
 * @date 2023-07-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Algorithm_Functions.h"

#include <vector>

std::vector<int> Sieves::eratosthenes(int N_limit) {
    bool* candidates = new bool[N_limit];

    for (int i = 2; i < N_limit; i++) {
        candidates[i] = true;
    }

    for (int i = 2; i < sqrt(N_limit); i++) {
        if (candidates[i]) {
            for (int j = (pow(i, 2)); j < N_limit; j += i) {
                candidates[j] = false;
            }
        }
    }

    std::vector<int> prime_numbers;

    for (int prime = 2; prime < N_limit; prime++) {
        if (candidates[prime]) {
            prime_numbers.push_back(prime);
        }
    }

    delete[] candidates;

    return prime_numbers;
}

bool is_palindrome(unsigned int number) {
    unsigned int reversed_number = 0;
    const unsigned int original_number = number;

    while (number > 0) {  // Reverse number by making successive divisions to
                          // obtain each digit.
        reversed_number *= 10;
        reversed_number += (number % 10);
        number /= 10;
    }

    if (reversed_number == original_number) {
        return true;
    }

    return false;
}