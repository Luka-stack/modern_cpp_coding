//
// Created by takacchi on 04/06/19.
//

#ifndef MODERN_CPP_EXC_PLAINDROME_H
#define MODERN_CPP_EXC_PLAINDROME_H

#include <iostream>
#include <vector>

/*
 * i*len + i = [i, j] = [row, col]
 */

std::string longest_palindrome(std::string_view str)
{
    size_t const len = str.length();
    size_t longest_begin_id = 0;
    size_t max_len = 1;
    std::vector<bool> table(len * len, false);

    // palindromes with the length of 1
    for (size_t i = 0; i < len; i++)
        table[i*len + i] = true;

    // palindromes with the length of 2
    for (size_t i = 0; i < len - 1; i++)
    {
        if (str[i] == str[i+1])
        {
            table[i*len + i + 1] = true;
            if (max_len < 2)
            {
                longest_begin_id = i;
                max_len = 2;
            }
        }
    }

    // palindromes with the length of 3 and more
    for (size_t k = 3; k <= len; k++)
    {
        for (size_t i = 0; i <= len - k; i++)
        {
            size_t j = i + k - 1;
            if (str[i] == str[j] && table[(i+1)*len + j-1])
            {
                table[i*len + j] = true;
                if (max_len < k)
                {
                    longest_begin_id = i;
                    max_len = k;
                }
            }
        }
    }

    return std::string(str.substr(longest_begin_id, max_len));

}

#endif //MODERN_CPP_EXC_PLAINDROME_H
