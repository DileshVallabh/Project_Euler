/**
 * @file Arithmetic.tcc
 * @author Dilesh Vallabh
 * @brief A header file of arithmetic functions for integer manipulation.
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#pragma once
#include <vector>

/**
 * @brief Compute the least common multiple of a list of numbers.
 *
 * @tparam T
 * @param list_numbers List of numbers to find the LCM of.
 * @return T Least common multiple.
 */
template <typename T>
T least_common_multiple(std::vector<T> list_numbers);

#include "Arithmetic.tcc"