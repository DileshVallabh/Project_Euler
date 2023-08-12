/**
 * @file Algorithm_Functions.tcc
 * @author Dilesh Vallabh
 * @brief Implementations of Algorithm_Functions template functions.
 * @version 0.1
 * @date 2023-06-21
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <math.h>

#include <iostream>
#include <vector>

using std::cout;
using std::endl;

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

template <typename T>
T least_common_multiple(std::vector<T> list_numbers) {
    T lcm = 1;

    std::map<T, T> primes_to_multiply;

    for (T i : list_numbers) {
        std::vector<T> factors = Factorisation::prime_factorise(i);
        std::vector<std::pair<T, T>> factors_exp =
            Factorisation::prime_exponents(factors);

        for (const auto& [key, value] : factors_exp) {
            if (primes_to_multiply.find(key) != primes_to_multiply.end()) {
                primes_to_multiply[key] = (value > primes_to_multiply[key])
                                              ? value
                                              : primes_to_multiply[key];
            } else {
                primes_to_multiply[key] = value;
            }
        }
    }

    for (const auto& [key, value] : primes_to_multiply) {
        lcm *= pow(key, value);
    }

    return lcm;
}
