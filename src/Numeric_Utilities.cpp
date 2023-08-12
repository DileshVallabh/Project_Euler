/**
 * @file Numeric_Utilities.cpp
 * @author Dilesh Vallabh
 * @brief Implementation of miscellaneous number-related utility functions.
 * @version 0.1
 * @date 2023-08-12
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "Numeric_Utilities.hpp"

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