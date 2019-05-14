//
// Created by takacchi on 14/05/19.
//

#ifndef MODERN_CPP_EXC_ANY_ARGS_NUMBER_H
#define MODERN_CPP_EXC_ANY_ARGS_NUMBER_H

#include <functional>
#include <iostream>

/*
 * Define function that takes arguments and return minimum of them
 */
template <typename T>
T minimum(T const a, T const b)
{
    return a < b ? a : b;
}

template <typename T1, typename... T>
T1 minimum(T1 a, T... args)
{
    return minimum(a, minimum(args...));
}

/*
 * Define function that takes arguments and return maximum of them
 */
template <typename T>
T maximum(T a, T b)
{
    return a > b ? a : b;
}

template <typename T1, typename... T>
T1 maximum(T1 a, T... args)
{
    return maximum(a, maximum(args...));
}

/*
 * Define function that summarize any number of arguments
 */
template <typename T>
T summarize(T const a, T const b)
{
    return a + b;
}

template <typename T1, typename... T>
T1 summarize(T1 a, T... args)
{
    return summarize(a, summarize(args...));
}

/*
 * Define function that prints all given arguments as one
 */
template <typename T>
void output(T text)
{
    std::cout << text << " ";
}

template <typename T1, typename... T>
void output(T1 a, T... args)
{
    std::cout << a << " ";
    output(args...);
}

/*
 * Define function that use compare function to compare
 */
template <class Compare, typename T>
T mini_usr(Compare comp, T const a, T const b)
{
    return comp(a, b) ? a : b;
}

template <class Compare, typename T1, typename... T>
T1 mini_usr(Compare comp, T1 a, T... args)
{
    return mini_usr(comp, a, (mini_usr(comp, args...)));
}

// For testing function above
template <class T> struct equaly {
    bool operator()(const T &x, const T &y) const { return x > y; }
};

/*
 * Define function that use summarize function
 */
template <class Summrize, typename T>
T sum_usr(Summrize sum, T const a, T const b)
{
    return sum(a, b);
}

template <class Summrize, typename T1, typename... T>
T1 sum_usr(Summrize sum, T1 a, T... args)
{
    return sum_usr(sum, a, (sum_usr(sum, args...)));
}

// For testing function above
template <class T> struct summy {
    T operator()(const T &x, const T &y) const { return x + y; }
};

// Test function for last two exercises
void test_two_last()
{
    auto build_in_compare = mini_usr(std::greater<>(), 3, 2, 1, 0);
    auto mine_compare = mini_usr(equaly<int>(), 3, 2, 1, 0);
    auto mine_summ = sum_usr(summy<int>(), 3, 2, 1, 0);

    std::cout << "Build in Compare: " << build_in_compare << std::endl;
    std::cout << "Mine Compare: " << mine_compare << std::endl;
    std::cout << "Mine Sum: " << mine_summ << std::endl;
}

#endif //MODERN_CPP_EXC_ANY_ARGS_NUMBER_H
