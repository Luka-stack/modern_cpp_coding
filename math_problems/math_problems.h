//
// Created by takacchi on 23/04/19.
//

#ifndef MODERN_CPP_EXC_MATH_PROBLEMS_H
#define MODERN_CPP_EXC_MATH_PROBLEMS_H

#include <string>
#include <vector>
#include <set>
#include <numeric>

/*
 * convenient functions
 */

// check if number is prime
bool is_prime(unsigned);

// sum all proper divisors of given number
unsigned sum_prop_div(unsigned);

std::string to_binary(unsigned, int);

/*
 * Exercises
 */

/*
 * Ex 1.
 * Write a function that sums all natural numbers from 0 to N which are divided by 3 or 5
 */
unsigned sum_all_three_and_five(unsigned);

/*
 * Ex 2.
 * Write a function that searches for Greatest Common Division
 */
unsigned gcd_rec(unsigned, unsigned);

unsigned gcd_itr(unsigned, unsigned);

/*
 * Ex 3.
 * Write a function that searches for Least Common Multiple
 */
unsigned lcm(unsigned, unsigned);

/*template <class InputIterator>
unsigned lcm_r(InputIterator, InputIterator);*/

template <class InputIterator>
unsigned lcm_r(InputIterator first, InputIterator last)
{
    return std::accumulate(first, last, 1, lcm);
}

/*
 * Ex 4.
 * Write a function that searches for smaller prime than given
 */
unsigned smaller_prime(unsigned);

/*
 * Ex 5.
 * Write a function that returns all pairs which numbers are prime and distance between them is 6
 */
std::set<unsigned> sixs_prime(unsigned);

/*
 * Ex 6.
 * Write a function that prints all abundant numbers in range <0, N>
 * Abundant numbers - In number theory, an abundant number or excessive number is a number for which the
 * sum of its proper divisors is greater than the number itself.
 */
std::vector<unsigned> abundant_numbers(unsigned);

/*
 * Ex 7.
 * Write a function that prints all amicable numbers in range <0, N>
 * Amicable numbers are two different numbers so related that the sum of
 * the proper divisors of each is equal to the other number.
 */
std::vector<std::pair<unsigned, unsigned>> amicable_numbers(unsigned);

/*
 * Ex 8.
 * Write a function that prints all Armstrong numbers which have 3 digit
 * Armstrong number (narcissistic) is a number that is the sum of its own digits
 * each raised to the power of the number of digits.
 */
std::vector<unsigned> print_armstrong();

/*
 * Ex 9.
 * Write a function that prints all first factors for given number
 */
std::vector<unsigned> first_factors(unsigned);

/*
 * Ex 10.
 * Write a function that decode and encode Gray's code and prints all 5-bits numbers
 */
unsigned gray_encode(unsigned);
unsigned gray_decode(unsigned);
void five_bit_gray();

/*
 * Ex 11.
 * Write a function that convert Arabic numbers to Rome numbers
 */
std::string to_rome(unsigned);

/*
 * Ex 12.
 * Write a function that computes the longest Collatz sequence
 */
std::pair<unsigned long long, long> coltz_problem(unsigned long long);

/*
 * Ex 13.
 * Write a function that computes PI with accuracy to two decimal places
 */
double compute_pi(unsigned);

/*
 * Ex 14.
 * Write a function that checks if given ISBN-10 code is correct
 */
bool check_isbn10(std::string_view);

bool check_full_isbn10(std::string_view);

bool check_full_isbn13(std::string_view);

bool check_isbn13(std::string_view);

#endif //MODERN_CPP_EXC_MATH_PROBLEMS_H
