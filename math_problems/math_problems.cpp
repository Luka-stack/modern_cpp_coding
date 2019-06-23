//
// Created by takacchi on 23/04/19.
//
#include <iostream>
#include <numeric>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>
#include <bitset>
#include <random>
#include <chrono>
#include <sstream>
#include <algorithm>
#include <utility>

/*
 * Implementation of functions in math_problems header
 */


/*
 * convenient functions implementations
 */
bool is_prime(unsigned num)
{
    if (num <= 3)
        return num > 1;
    else if (num % 2 == 0 || num % 3 == 0)
        return false;
    else
    {
        for (int i = 5; i * i <= num; i++)
        {
            if (num % i == 0 || num % (i + 2) == 0)
                return false;
        }

        return true;
    }
}

unsigned sum_prop_div(unsigned num)
{
    int result = 1;

    for (int i = 2; i <= std::sqrt(num); i++)
    {
        if (num % i == 0)
            result += (i == (num / i)) ? i : (i + num / i);
    }

    return result;
}

std::string to_binary(unsigned val, int digits)
{
    return std::bitset<32>(val).to_string().substr(32-digits, digits);
}

bool is_hyphen(char const ch)
{
    return ch == '-';
}

// Math Problems Header Implementations

unsigned sum_all_three_and_five(const unsigned N)
{
    unsigned long long result = 0;

    for (unsigned i = 3; i <= N; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            result += i;
    }

    return result;
}

unsigned gcd_rec(const unsigned a, const unsigned b)
{
    return b == 0 ? a : gcd_rec(b, a % b);
}

unsigned gcd_itr(unsigned a, unsigned b)
{
    while (b != 0)
    {
        unsigned rem = a % b;
        a = b;
        b = rem;
    }

    return a;
}

unsigned lcm(unsigned a, unsigned b)
{
    int com_div = gcd_rec(a, b);
    return com_div ? (a * (b / com_div)) : 0;
}

/*template <class InputIterator>
unsigned lcm_r(InputIterator first, InputIterator last)
{
    return std::accumulate(first, last, 1, lcm);
}*/

unsigned smaller_prime(unsigned N)
{
    for (int i = N; i > 1; i--)
    {
        if (is_prime(i))
            return i;
    }

    return 0;
}

std::set<unsigned> sixs_prime(unsigned N)
{
    std::set<unsigned> results;

    for (unsigned i = 2; i <= N; i++)
    {
        if (is_prime(i) && is_prime(i + 6))
        {
            results.insert(i);
            results.insert(i+6);
        }
    }

    return results;
}

std::vector<unsigned> abundant_numbers(unsigned N)
{
    std::vector<unsigned> results;

    for (int i = 12; i <= N; i++)
    {
        int abundant = sum_prop_div(i);
        if (abundant > i)
        {
            results.push_back(i);
        }
    }

    return results;
}

std::vector<std::pair<unsigned, unsigned>> amicable_numbers(unsigned N)
{
    std::vector<std::pair<unsigned, unsigned>> results;

    for (int i = 4; i < N; i++)
    {
        int sum_one = sum_prop_div(i);
        if (sum_one < N) {
            int sum_two = sum_prop_div(sum_one);
            if (sum_two == i && i != sum_one)
                results.emplace_back(i, sum_one);
        }
    }

    return results;
}

std::vector<unsigned> print_armstrong()
{
    std::vector<unsigned> results;

    for (int a = 1; a < 10; a++)
    {
        for (int b = 0; b < 10; b++)
        {
            for (int c = 0; c < 10; c++)
            {
                int number = a * 100 + b * 10 + c;
                int sum = (a*a*a) + (b*b*b) + (c*c*c);
                if (number == sum)
                    results.push_back(number);
            }
        }
    }

    return results;
}

std::vector<unsigned> first_factors(unsigned num)
{
    std::vector<unsigned> factors;
    std::stringstream result;

    while (num % 2 == 0)
    {
        factors.push_back(2);
        result << 2 <<  " ";
        num /= 2;
    }

    for (unsigned i = 3; i < std::sqrt(num); i += 2)
    {
        while (num % i == 0) {
            result << i << " ";
            factors.push_back(i);
            num /= i;
        }
    }

    if (num > 2)
    {
        factors.push_back(num);
        result << num;
    }

    //std::cout << result.str();

    for (auto i : factors)
        std::cout << i << std::endl;

    return factors;
}

unsigned gray_encode(unsigned num)
{
    return num ^ (num >> 1);
}

unsigned gray_decode(unsigned gray)
{
    for (unsigned bit = 1 << 31; bit > 1; bit >>= 1)
    {
        if (gray & bit)
            gray ^= bit >> 1;
    }

    return gray;
}

void five_bit_gray()
{
    std::cout << "Number\tBinary\t\tGray Code\tDecoded Gray\n";

    for (unsigned i = 0; i < 32; i++)
    {
        auto enc_gray = gray_encode(i);
        auto dec_gray = gray_decode(enc_gray);

        std::cout << i << "\t\t" << to_binary(i, 5) << "\t\t" << to_binary(enc_gray, 5) << "\t\t" << dec_gray << "\n";
    }
}

std::string to_rome(unsigned num)
{
    // 0 = nulla
    // I = 1
    // V = 5
    // X = 10
    // L = 50
    // C = 100
    // D = 500
    // M = 1000

    if (num != 0) {

        std::string result;

        std::vector<std::pair<unsigned, const char *>> roman_map {
                {1000, "M"},
                {900,  "CM"},
                {500,  "D"},
                {400,  "CD"},
                {100,  "C"},
                {90,   "XC"},
                {50,   "L"},
                {40,   "XL"},
                {10,   "X"},
                {9,    "IX"},
                {5,    "V"},
                {4,    "IV"},
                {1,    "I"}
        };

        // Position is very important and must be like in roman_map.
        // That's why map cannot be used
/*        std::map<unsigned, const char *> roman_map2 {
                {1,    "I"},
                {4,    "IV"},
                {5,    "V"},
                {9,    "IX"},
                {10,   "X"},
                {40,   "XL"},
                {50,   "L"},
                {90,   "XC"},
                {100,  "C"},
                {400,  "CD"},
                {500,  "D"},
                {900,  "CM"},
                {1000, "M"},
        };*/

        for (auto const &items : roman_map)
        {
            while (num >= items.first) {
                result += items.second;
                num -= items.first;
            }
        }

        return result;
    }

    return "nulla";
}

std::pair<unsigned long long, unsigned long> coltz_problem(unsigned long long N)
{
    long length = 0;
    unsigned long long number = 0;
    std::vector<int> cache(N + 1, 0);

    for (unsigned long long i = 2; i <= N; i++)
    {
        auto n = i;
        long steps = 0;
        while (n != 1 && n >= i)
        {
            if (n % 2 == 0)
                n /= 2;
            else
                n = n*3 + 1;

            steps++;
        }

        cache[i] = steps + cache[n];

        if (cache[i] > length)
        {
            length = cache[i];
            number = i;
        }
    }

    return std::make_pair(number, length);
}

double compute_pi(unsigned samples)
{
    /*std::mt19937 engine;
    std::uniform_real_distribution<> dist;*/

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine engine(seed);
    std::uniform_real_distribution<> dist;

    auto hits = 0;
    for(auto i = 0; i < samples; i++)
    {
        auto x = dist(engine);
        auto y = dist(engine);

        // (x-a)^2 + (y-b)^2 = d^2, a=0, b=0, d=1
        // x^2 + y^2 = 1
        //if (y <= std::sqrt(1 - x*x))
        if ((y*y) + (x*x) <= 1)
            hits++;
    }

    return 4.0 * hits / samples;
}

bool check_isbn10(std::string_view isbn)
{
    // only 10 digits.. check
    if (isbn.size() == 10 && std::count_if(isbn.begin(), isbn.end(), isdigit) == 10)
    {
        // to multiply following numbers in code (10 -> 1)
        unsigned wage = 10;
        // sum of every digit in isbn code, start from 0
        unsigned sum = std::accumulate(
                isbn.begin(), isbn.end(), 0,
                [&wage](unsigned const total, char const number)
                {
                    return total + wage-- * (number - '0');
                });

        if (sum % 11 == 0)
            return true;
    }

    return false;
}

bool check_full_isbn10(std::string_view isbn)
{
    if (isbn.size() == 13 && std::count_if(isbn.begin(), isbn.end(), isdigit) == 10)
    {
        unsigned wage = 10;
        unsigned sum = std::accumulate(
                isbn.begin(), isbn.end(), 0,
                [&wage](unsigned const total, char const ch)
                {
                    if (ch == '-')
                        return total;

                    return total + wage-- * (ch - '0');
                });

        if (sum % 11 == 0)
            return true;
    }

    return false;
}

bool check_full_isbn13(std::string_view isbn)
{
    if (isbn.size() == 17 && std::count_if(isbn.begin(), isbn.end(), isdigit) == 13
        && std::count_if(isbn.begin(), isbn.end(), is_hyphen) == 4)
    {
        unsigned wage = 3;
        unsigned sum = std::accumulate(
                isbn.begin(), isbn.end(), 0,
                [&wage](unsigned const total, char const ch) {
                    if (ch == '-')
                        return total;

                    wage = (wage == 3) ? 1 : 3;

                    return total + wage * (ch - '0');
                });

        if (sum % 10 == 0)
            return true;
    }

    return false;
}

bool check_isbn13(std::string_view isbn)
{
    if (isbn.size() == 13 && std::count_if(isbn.begin(), isbn.end(), isdigit) == 13)
    {
        unsigned wage = 3;
        unsigned sum = std::accumulate(
                isbn.begin(), isbn.end(), 0,
                [&wage](unsigned const total, char const ch)
                {
                    wage = (wage == 3) ? 1 : 3;

                    return total + wage * (ch - '0');
                });

        if (sum % 10 == 0)
            return true;
    }

    return false;
}