#include <iostream>
//#include "math_problems/math_problems.h"
#include "language_functions/Ipv4.h"
#include "language_functions/Great2D.h"

int main()
{
    Great2D <int, 3, 3> great2D;

    great2D.fill(5);
    std::cout << great2D;

    return 0;
}
