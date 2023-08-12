/**
 * @file Prime_Sieves.tcc
 * @author Dilesh Vallabh
 * @brief Implementation of prime sieve algorithms for generating prime numbers.
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <math.h>

#include <vector>

namespace Sieves {

template <typename T>
std::vector<T> Sieves::eratosthenes(T N_limit) {
    bool* candidates = new bool[N_limit];

    for (T i = 2; i < N_limit; i++) {
        candidates[i] = true;
    }

    for (T i = 2; i < sqrt(N_limit); i++) {
        if (candidates[i]) {
            for (T j = (pow(i, 2)); j < N_limit; j += i) {
                candidates[j] = false;
            }
        }
    }

    std::vector<T> prime_numbers;

    for (T prime = 2; prime < N_limit; prime++) {
        if (candidates[prime]) {
            prime_numbers.push_back(prime);
        }
    }

    delete[] candidates;

    return prime_numbers;
}

}  // namespace Sieves