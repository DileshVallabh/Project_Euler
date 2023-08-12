/**
 * @file Factorisation.tcc
 * @author Dilesh Vallabh
 * @brief Implementations of factorisation template functions.
 * @version 0.1
 * @date 2023-08-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#include <math.h>

#include <vector>

namespace Factorisation {
template <typename T>
std::vector<T> prime_factorise(T N) {
    std::vector<T> factors;

    if (N == 1) {
        return std::vector<T>{1};
    }

    while (N % 2 == 0) {
        factors.push_back(2);
        N /= 2;
    }

    for (T i = 3; i <= sqrt(N); i += 2) {
        while (N % i == 0) {
            factors.push_back(i);
            N /= i;
        }
    }

    if (N > 2) {
        factors.push_back(N);
    }

    return factors;
}

template <typename T>
std::vector<std::pair<T, T>> prime_exponents(std::vector<T>& prime_factors) {
    std::map<T, T> factors_map;

    for (T i : prime_factors) {
        factors_map[i]++;
    }

    std::vector<std::pair<T, T>> factors;

    for (const auto& pair_value : factors_map) {
        factors.push_back(pair_value);
    }

    return factors;
}

}  // namespace Factorisation