#pragma once
#include <vector>

/**
 * @brief Algorithms to find the factors of a number.
 */
namespace Factorisation {

/**
 * @brief Find all the prime factors of a number.
 *
 * @tparam T
 * @param N Number to factorise.
 * @return std::vector<T> A vector containing the prime factors.
 */
template <typename T>
std::vector<T> prime_factorise(T N);

/**
 * @brief Compute the exponents for each prime factor from an explicit list of
 * primes.
 *
 * @tparam T
 * @param prime_factors List of all prime factors.
 * @return std::vector<std::pair<T, T>> A vector containing a pair of the form
 * (prime, exponent).
 */
template <typename T>
std::vector<std::pair<T, T>> prime_exponents(std::vector<T>& prime_factors);

}  // namespace Factorisation

#include "Factorisation.tcc"