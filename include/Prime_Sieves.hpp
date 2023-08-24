/**
 * @file Prime_Sieves.hpp
 * @author Dilesh Vallabh
 * @brief A collection of prime sieve algorithms for efficiently generating
 * prime numbers.
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <vector>

/**
 * @brief Sieves for finding prime numbers.
 */
namespace Sieves {

/**
 * @brief Find all primes below a limit using the Sieve of Eratosthenes.
 *
 * @param N_limit Limit of the prime search.
 *
 * @return Vector of all primes below N_limit.
 */
std::vector<int> eratosthenes(int N_limit);

template <std::integral T>
std::vector<T> eratosthenes(T N_limit);

}  // namespace Sieves

#include "Prime_Sieves.tcc"