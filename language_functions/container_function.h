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
bool contains_none(C const& c, T&&... val)
{
    return !contains_any(c, std::forward<T>(val)...);
}


#endif //MODERN_CPP_EXC_CONTAINER_FUNCTION_H
