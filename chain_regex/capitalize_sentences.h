//
// Created by takacchi on 03/06/19.
//

#ifndef MODERN_CPP_EXC_CAPITALIZE_SENTENCES_H
#define MODERN_CPP_EXC_CAPITALIZE_SENTENCES_H

#include <iostream>
#include <sstream>

template <class Object>
using temp_string = std::basic_string<Object, std::char_traits<Object>, std::allocator<Object>>;

template <class Object>
using temp_stringstream = std::basic_stringstream<Object, std::char_traits<Object>, std::allocator<Object>>;

template <class Object>
temp_string<Object> my_capitalize(temp_string<Object> const& txt)
{
    temp_stringstream<Object> result_stream;
    bool new_word = true;

    for (auto const ch : txt)
    {
        new_word = new_word || ispunct(ch) || isspace(ch);
        if (isalpha(ch))
        {
            if (new_word)
            {
                result_stream << static_cast<Object>(toupper(ch));
                new_word = false;
            } else
                result_stream << static_cast<Object>(tolower(ch));
        } else
            result_stream << ch;
    }

    return result_stream.str();
}

#endif //MODERN_CPP_EXC_CAPITALIZE_SENTENCES_H
