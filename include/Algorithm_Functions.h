/**
 * @file Algorithm_Functions.h
 * @brief Header file containing useful functions for Project Euler.
 * @author Dilesh Vallabh
 */

#pragma once
#include <map>
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

template <typename T>
std::vector<T> eratosthenes(T N_limit);

}  // namespace Sieves

namespace Logarithmic_Integral {

/**
 * @brief Approximate the Logarithmic Integral at x using Ramanujan's
 * approximation.
 *
 * @param x
 * @param tolerance
 * @return double Approximation
 */
double ramanujan_approximation(const double x, const double tolerance = 1e-12);

namespace Exponential_Definition {

/**
 * @brief Calculate the Logarithmic Integral at x using the Exponentional
 * Integral.
 *
 * @param x
 * @return double Value of li(x)
 */
double li(const double x);

/**
 * @brief Compute the inverse Logarithmic Integral using Newton's method.
 *
 * @param y
 * @param tolerance
 * @return double Inverse of Li(x).
 */
double inverse_li(const double y, const double tolerance = 1e-6,
                  const unsigned int max_iterations = 100);
}  // namespace Exponential_Definition
}  // namespace Logarithmic_Integral

/// @brief Determines if a number is a palindrome.
/// @param number
/// @return bool True if palindrome.
bool is_palindrome(unsigned int number);



#include "Algorithm_Functions.tcc"
