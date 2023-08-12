/**
 * @file Arithmetic.tcc
 * @author Dilesh Vallabh
 * @brief A collection of arithmetic template functions for integer manipulation.
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <Factorisation.hpp>
#include <map>
#include <vector>

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