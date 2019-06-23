//
// Created by takacchi on 23/06/19.
//

#include <cmath>
#include <iostream>
#include "declarations.h"

unsigned digits(unsigned const n)
{
    return n > 0 ? (int)log10((double)n) + 1 : 1;
}

void pascal_triangle(unsigned row)
{
    for (int i = 0; i < row; i++)
    {
        auto x = 1;
        std::cout << std::string((row-i-1)*(row/2), ' ');
        //std::cout << std::string((row-i)*(row/2), ' ');
        for (int j = 0; j <= i; j++)
        {
            auto y = x;
            x = x * (i - j) / (j + 1);
            //auto maxlen = digits(x) - 1;
            //std::cout << y << std::string(row - 1 - maxlen - row%2, ' ');
            std::cout << y << std::string(3, ' ');
        }
        std::cout << std::endl;
    }
}

