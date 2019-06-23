//
// Created by takacchi on 04/06/19.
//

#ifndef MODERN_CPP_EXC_SPLIT_STRING_H
#define MODERN_CPP_EXC_SPLIT_STRING_H

#include <iostream>
#include <sstream>
#include <vector>

template <class Object>
using temp_string = std::basic_string<Object, std::char_traits<Object>, std::allocator<Object>>;

template <class Object>
using temp_stringstream = std::basic_stringstream<Object, std::char_traits<Object>, std::allocator<Object>>;

template <class Object>
std::vector<temp_string <Object>> split(temp_string<Object> txt, Object const delimiter)
{
    auto stream = temp_stringstream<Object> { txt };
    auto result = std::vector<temp_string <Object>> {};
    auto token  = temp_string<Object>();

    while (std::getline(stream, token, delimiter))
    {
        if (!token.empty())
            result.push_back(token);
    }

    return result;
}

template <class Object>
std::vector<temp_string <Object>> split(temp_string<Object> txt, temp_string<Object> const& delimiters)
{
    auto results = std::vector<temp_string <Object>> {};
    size_t pos, prev_pos = 0;

    // until the end of the string
    while ((pos = txt.find_first_of(delimiters, prev_pos)) != std::string::npos)
    {
        if (pos > prev_pos)
            results.push_back(txt.substr(prev_pos, pos-prev_pos));
        prev_pos = pos + 1;
    }

    if (prev_pos < txt.length())
        results.push_back(txt.substr(prev_pos, std::string::npos));

    return results;
}

#endif //MODERN_CPP_EXC_SPLIT_STRING_H