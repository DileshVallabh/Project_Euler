/**
 * @file Euler_Problems.h
 *
 * @brief Functions returning the answers to Project Euler problems.
 */

#pragma once

/**
 * @brief Multiples of 3 or 5.
 * @param maximum Maximum value of algorithm.
 * @return Sum of all the multiples of 3 or 5 below maximum.
 */
unsigned int problem_1(unsigned int maximum);

/**
 * @brief Even Fibonacci Numbers
 * @param fibonacci_maximum Maximum of the terms in the Fibonacci sequence.
 * @return Sum of the even-valued terms.
 */
unsigned int problem_2(unsigned int fibonacci_maximum);

/**
 * @brief Largest Prime Factor.
 * @param number Number to query.
 * @return The largest prime factor of the query number.
 */
unsigned long int problem_3(unsigned long int number);

/**
 * @brief Find largest palindromic product in range.
 *
 * @param min Lower bound of range.
 * @param max Upper bound of range.
 * @return unsigned int Largest palindromic product.
 */
unsigned int problem_4(unsigned int min, unsigned int max);

/**
 * @brief Find the lowest common multiple.
 *
 * @param maximum The limit of the query numbers from 1..limit.
 * @return unsigned int LCM
 */
unsigned int problem_5(unsigned int maximum);

/**
 * @brief Find the difference of the square of the sum and the sum of the
 * squares.
 *
 * @param maximum Limit of sequence.
 */
void problem_6(unsigned int maximum);

void problem_7(unsigned int n);