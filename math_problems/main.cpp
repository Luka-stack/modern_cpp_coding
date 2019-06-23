//
// Created by takacchi on 23/06/19.
// Test For Exercises
//

#include <iostream>
#include <assert.h>
#include "math_problems.h"

void check_1();
void check_2();
void check_3();
void check_4();
void check_5();
void check_6();
void check_7();
void check_8();
void check_9();
void check_11();
void check_12();
void check_13();
void check_14();

int main()
{
    check_1();
    check_2();
    check_3();
    check_4();
    check_5();
    check_6();
    check_7();
    check_8();
    check_9();
    // check_10
    five_bit_gray();
    check_11();
    check_12();
    check_13();
    check_14();

    return 0;
}

// testing functions

void check_1()
{
    // from 0 to 20 (3, 5, 6, 9, 10, 12, 15, 18, 20) = 98

    const unsigned correct = 98;
    unsigned result = sum_all_three_and_five(20);

    assert(result == correct);
}

void check_2()
{
   // Greatest Common Division for (120, 540) = 60

   const unsigned correct = 60;
   unsigned rec_res = gcd_rec(120, 540);
   unsigned itr_res = gcd_itr(120, 540);

   assert(rec_res == correct);
   assert(itr_res == correct);
}

void check_3()
{
    // Least Common Multiple for numbers '65, 10, 5' is 130

    const unsigned correct = 130;
    std::vector<int> numbers {65, 10, 5};

    unsigned result = lcm_r(std::begin(numbers), std::end(numbers));

    assert(result == correct);
}

void check_4()
{
    // first prime number less than 199 is 197

    const unsigned correct = 197;
    unsigned result = smaller_prime(199);

    assert(result == correct);
}

void check_5()
{
    // in range [0,20] primes separated by 6 are:
    const std::vector<unsigned> correct {5, 7, 11, 13, 17, 19, 23};

    std::set<unsigned> results = sixs_prime(20);

    assert(std::equal(std::begin(results), std::end(results), std::begin(correct)));
}

void check_6()
{
    // in range [0, 20] abundant_numbers are:
    const std::vector<int> correct {12, 18, 20};

    std::vector<unsigned> results = abundant_numbers(20);

    assert(std::equal(std::begin(results), std::end(results), std::begin(correct)));
}

void check_7()
{
    // amicable numbers in range [0, 1000] are:
    std::vector<std::pair<unsigned, unsigned>> correct;
    correct.emplace_back(220, 284);
    correct.emplace_back(284, 220);

    std::vector<std::pair<unsigned, unsigned>> results = amicable_numbers(1000);

    assert(std::equal(std::begin(results), std::end(results), std::begin(correct)));
}

void check_8()
{
    // All 3 digits armstrong numbers are:
    const std::vector<unsigned> correct = {153, 370, 371, 407};

    std::vector<unsigned> results = print_armstrong();

    assert(std::equal(std::begin(results), std::end(results), std::begin(correct)));
}

void check_9()
{
    // first factors for 80 are:
    const std::vector<unsigned> correct = {2, 2, 2, 2, 5};

    std::vector<unsigned> results = first_factors(80);

    assert(std::equal(std::begin(results), std::end(results), std::begin(correct)));
}

void check_11()
{
    // 1998 in Rome is MCMXCVIII
    const std::string correct = "MCMXCVIII";

    std::string result = to_rome(1998);

    assert(result == correct);
}

void check_12()
{
    // in range [0, 25] the longest collatz number is 25 (length: 23)
    const std::pair<unsigned long long, unsigned long> correct = std::pair(25, 23);

    std::pair result = coltz_problem(25);

    assert(correct.first == result.first);
    assert(correct.second == result.second);
}

void check_13()
{
    std::cout << "Pi: 3.14159... For 10000 samples my Pi is: " << compute_pi(10000);
}

void check_14()
{
    assert(check_isbn10("0306406152"));
    assert(check_full_isbn10("0-19-852663-6"));
    assert(check_full_isbn13("978-3-16-148410-0"));
    assert(check_isbn13("9783161484100"));
}