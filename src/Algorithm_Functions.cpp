/**
 * @file Algorithm_Functions.cpp
 * @author Dilesh Vallabh
 * @brief Implementations of Algorithm_Functions.
 * @version 0.1
 * @date 2023-07-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "Algorithm_Functions.h"

#include <math.h>

#include <algorithm>
#include <boost/math/constants/constants.hpp>
#include <boost/math/special_functions/expint.hpp>
#include <boost/math/special_functions/factorials.hpp>
#include <iostream>
#include <limits>
#include <vector>

using std::cout;
using std::endl;

using boost::math::factorial;

namespace Logarithmic_Integral {

/// @todo Validation required.
double ramanujan_approximation(const double x, const double tolerance) {
    const double GAMMA = boost::math::constants::euler<double>();

    double li = (log(log(x))) + GAMMA;
    const double sqrt_x = sqrt(x);

    unsigned int n = 1;
    double sum = 0;
    double delta = 0;
    do {
        double term_1_numerator = (pow(-1, (n - 1))) * (pow(log(x), n));
        double term_1_denominator = factorial<double>(n) * pow(2, (n - 1));

        unsigned int limit = floor((n - 1) / 2);
        double sum_2 = 0;
        for (unsigned int k = 0; k <= limit; k++) {
            sum_2 += 1 / ((2 * k) + 1);
        }

        delta = sqrt_x * (term_1_numerator / term_1_denominator) * sum_2;
        sum += delta;
        n++;
    } while (delta >= tolerance);

    li += sqrt(x) * sum;

    return li;
}

namespace Exponential_Definition {

double li(const double x) {
    if (x == 1) {
        return -std::numeric_limits<double>::infinity();
    }

    double log_x = log(x);

    double log_int = boost::math::expint(log_x);

    return log_int;
}

double inverse_li(const double y, const double tolerance,
                  const unsigned int max_iterations) {
    double x_0 = y * log(y);  // initial approximation of x.

    for (unsigned int i = 0; i <= max_iterations; i++) {
        double y_0 = li(x_0);
        double derivative = (li(x_0 + tolerance) - li(x_0 - tolerance)) /
                            (2 * tolerance);  // central difference.

        double delta = ((y_0 - y) / derivative);
        x_0 = x_0 - delta;

        if (fabs((li(x_0) - y)) < tolerance) {
            break;
        }
    }

    return x_0;
}

}  // namespace Exponential_Definition
}  // namespace Logarithmic_Integral

std::vector<int> Sieves::eratosthenes(int N_limit) {
    bool* candidates = new bool[N_limit];

    for (int i = 2; i < N_limit; i++) {
        candidates[i] = true;
    }

    for (int i = 2; i < sqrt(N_limit); i++) {
        if (candidates[i]) {
            for (int j = (pow(i, 2)); j < N_limit; j += i) {
                candidates[j] = false;
            }
        }
    }

    std::vector<int> prime_numbers;

    for (int prime = 2; prime < N_limit; prime++) {
        if (candidates[prime]) {
            prime_numbers.push_back(prime);
        }
    }

    delete[] candidates;

    return prime_numbers;
}

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