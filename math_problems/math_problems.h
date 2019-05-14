//
// Created by takacchi on 23/04/19.
//

#ifndef MODERN_CPP_EXC_MATH_PROBLEMS_H
#define MODERN_CPP_EXC_MATH_PROBLEMS_H

/*
 * convenient functions
 */

#include <string>

// check if number is prime
bool is_prime(unsigned);

// sum all proper divisors of given number
unsigned sum_prop_div(unsigned);

std::string to_binary(unsigned, int);

/*
 * Write a function that sums all natural numbers from 0 to N which are divided by 3 or 5
 */
unsigned sum_all_three_and_five(unsigned);

/*
 * Write a function that searches for Greatest Common Division
 */
unsigned gcd_rec(unsigned, unsigned);

unsigned gcd_itr(unsigned, unsigned);

/*
 * Write a function that searches for least Common Multiple
 */
unsigned lcm(unsigned, unsigned);

template <class InputIterator>
unsigned lcm_ext(InputIterator, InputIterator);

/*
 * Write a function that searches for smaller prime than given
 */
unsigned smaller_prime(unsigned);

/*
 * Write a function that prints all pairs which numbers are prime and distance between them is 6
 */
void sixs_prime(unsigned);

/*
 * Write a function that prints all abundant numbers in range <0, N>
 * Abundant numbers - In number theory, an abundant number or excessive number is a number for which the
 * sum of its proper divisors is greater than the number itself.
 */
void abundant_numbers(unsigned);

/*
 * Write a function that prints all amicable numbers in range <0, N>
 * Amicable numbers are two different numbers so related that the sum of
 * the proper divisors of each is equal to the other number.
 */
void amicable_numbers(unsigned);

/*
 * Write a function that prints all Armstrong numbers which have 3 digit
 * Armstrong number (narcissistic) number is a number that is the sum of its own digits
 * each raised to the power of the number of digits.
 */
void print_armstrong();

/*
 * Write a function that prints all first factors for given number
 */
void first_factors(unsigned);

/*
 * Write a function that decode and encode Gray's code and prints all 5-bits numbers
 */
unsigned gray_encode(unsigned);
unsigned gray_decode(unsigned);
void five_bit_gray();

/*
 * Write a function that convert Arabic numbers to Rome numbers
 */
std::string to_rome(unsigned);

/*
 * Write a function that computes the longest Collatz sequence
 */
std::pair<unsigned long long, long> coltz_problem(unsigned long long);

/*
 * Write a function that computes PI with accuracy to two decimal places
 */
double compute_pi(unsigned);

/*
 * Write a function that checks if given ISBN-10 code is correct
 */
bool check_isbn10(std::string_view);

bool check_full_isbn10(std::string_view);

bool check_full_isbn13(std::string_view);

bool check_isbn13(std::string_view);

#endif //MODERN_CPP_EXC_MATH_PROBLEMS_H
