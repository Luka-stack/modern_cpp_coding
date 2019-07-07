//
// Created by takacchi on 03/06/19.
//

#ifndef MODERN_CPP_EXC_JOIN_STRING_H
#define MODERN_CPP_EXC_JOIN_STRING_H

#include <iostream>
#include <sstream>
#include <iterator>

// not working with lists
/*template <typename Iter>
std::string join_strings(Iter begin, Iter end, char const* const separator)
{
    std::ostringstream stream;
    std::copy(begin, end-1, std::ostream_iterator<std::string>(stream, separator));

    stream << *(end-1);

    return stream.str();
}*/


template <typename Iter>
std::string join_strings(Iter begin, Iter end, char const* const separator)
{
    std::ostringstream stream;
    std::copy(begin, std::prev(end), std::ostream_iterator<std::string>(stream, separator));

    stream << *(std::prev(end));

    return stream.str();
}

template <typename Cont>
std::string join_strings(Cont const& container, char const* const separator)
{
    if (container.size() == 0)
        return std::string();

    return join_strings(std::begin(container), std::end(container), separator);
}

#endif //MODERN_CPP_EXC_JOIN_STRING_H
