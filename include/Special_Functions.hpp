/**
 * @file Special_Functions.hpp
 * @author Dilesh Vallabh
 * @brief Contains of special mathematical functions and algorithms.
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once

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