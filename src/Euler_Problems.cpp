/**
 * @file Euler_Problems.cpp
 * @brief Implementation file for Euler_Problems.
 */

#include "Euler_Problems.h"

#include <math.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "Algorithm_Functions.h"

using std::cout;
using std::endl;

unsigned int problem_1(unsigned int maximum) {
    unsigned int sum = 0;

    for (unsigned int i = 0; i < maximum; i += 3) {
        sum += i;
    }

    for (unsigned int i = 0; i < maximum; i += 5) {
        sum += i;
    }

    for (unsigned int i = 0; i < maximum; i += (3 * 5)) {
        sum -= i;
    }

    return sum;
}

unsigned int problem_2(unsigned int fibonacci_maximum) {
    unsigned int sum = 0;

    unsigned int num1 = 0;
    unsigned int num2 = 1;

    while (num2 < fibonacci_maximum) {
        if (num2 % 2 == 0) {
            sum += num2;
        }

        unsigned int temp = num1 + num2;
        num1 = num2;
        num2 = temp;
    }

    return sum;
}

unsigned long int problem_3(unsigned long int number) {
    std::vector<unsigned long int> prime_factors =
        Factorisation::prime_factorise(number);

    unsigned long int largest_prime_factor =
        *std::max_element(prime_factors.begin(), prime_factors.end());

    return largest_prime_factor;
}

unsigned int problem_4(unsigned int min, unsigned int max) {
    unsigned int largest_palindrome = 0;

    for (unsigned int a = max; a >= min; a--) {
        for (unsigned int b = a; b >= min; b--) {
            unsigned int P = a * b;
            if (is_palindrome(P) && P > largest_palindrome) {
                largest_palindrome = P;
            }
        }
    }

    return largest_palindrome;
}

unsigned int problem_5(unsigned int maximum) {
    std::vector<unsigned int> list_numbers(maximum);

    for (unsigned int i = 1; i <= maximum; i++) {
        list_numbers[i - 1] = i;
    }

    return least_common_multiple(list_numbers);
}

/**
 * @note Brute force approach.
 */
void problem_6(const unsigned int maximum) {
    unsigned int sum_of_squares = 0;
    unsigned int sum = 0;

    for (unsigned int i = 0; i <= maximum; i++) {
        sum += i;
        sum_of_squares += pow(i, 2);
    }
    unsigned int difference = (pow(sum, 2) - sum_of_squares);
    cout << difference << endl;
}

void problem_7(unsigned int n) {
    double limit = Logarithmic_Integral::Exponential_Definition::inverse_li(n);
    limit = (limit * 1.5); // Account for error -> pi(x)-li(x).

    unsigned int sieve_limit = ceil(limit);

    cout << "Limit:\t" << sieve_limit << endl;

    std::vector<unsigned int> primes = Sieves::eratosthenes(sieve_limit);

    cout << "Number of prime:\t" << primes.size() << endl;

    unsigned int queried_prime = primes[n - 1];

    cout << queried_prime << endl;
}