//
// Created by takacchi on 14/05/19.
//

#ifndef MODERN_CPP_EXC_CONTAINER_FUNCTION_H
#define MODERN_CPP_EXC_CONTAINER_FUNCTION_H

#include <iostream>
#include <functional>
#include <vector>
#include <list>
#include <iterator>

/*
 * Define function that takes any numbers of arguments and
 * add them to container
 */
template<typename C, typename... Args>
void push_back(C& c, Args&&... args)
{
    (c.push_back(args), ...);
}

// Test
void add_to_container()
{
    std::vector<int> v;
    push_back(v, 1, 2, 3, 4, 5);
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, "\n"));

    std::cout << "\n\n";

    std::list<double> l;
    push_back(l, 1.4, 2.2, 3, 4.1, 5.9, 1.4, 2.2, 3, 4.1, 5.9);
    std::copy(std::begin(l), std::end(l), std::ostream_iterator<double>(std::cout, "\n"));
}

/*
 * Define function that check if any, none, of all arguments are in
 */
template<class C, class T>
bool contains(C const& c, T const& val)
{
    return std::end(c) != std::find(std::begin(c), std::end(c), val);
}

template<class C, class... T>
bool contains_any(C const& c, T&&... val)
{
    return (... || contains(c, val));
}

template<class C, class... T>
bool contains_all(C const& c, T&&... val)
{
    return (... && contains(c, val));
}

template<class C, class... T>
bool constains_none(C const& c, T&&... val)
{
    return !contains_any(c, std::forward<T>(val)...);
}

// Test
void check_cointainer()
{
    std::vector<int> cont {1, 2, 3, 4, 5};

    std::cout << "Contains any: 1.[10,9,4,2] | 2.[10,11,12,13]\n";
    std::cout << contains_any(cont, 10, 9, 4, 2) << std::endl;
    std::cout << contains_any(cont, 10, 11, 12, 13) << std::endl;

    std::cout << "\nContains all: 1.[1,2,3,4,5] | 2.[1,2,3,4,19]\n";
    std::cout << contains_all(cont, 1, 2, 3, 4, 5) << std::endl;
    std::cout << contains_all(cont, 1, 2, 3, 4, 19) << std::endl;

    std::cout << "\nContains none: 1.[1,2,3,4, 5] | 2.[10,12,13,14,19]\n";
    std::cout << constains_none(cont, 1, 2, 3, 4, 5) << std::endl;
    std::cout << constains_none(cont, 10, 12, 13, 14, 19) << std::endl;
}

#endif //MODERN_CPP_EXC_CONTAINER_FUNCTION_H
