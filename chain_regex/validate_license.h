//
// Created by takacchi on 04/06/19.
//

#ifndef MODERN_CPP_EXC_VALIDATE_LICENSE_H
#define MODERN_CPP_EXC_VALIDATE_LICENSE_H

#include <iostream>
#include <regex>

// AAA-DD 1111 / AAA-DD 111
// [A-Z]{3}-[A-Z]{2} \d{3,4}

bool validate_plate(std::string_view str)
{
    std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
    return std::regex_match(str.data(), rx);
}

std::vector<std::string> extract_validate_plate(std::string const& str)
{
    std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
    std::smatch match;
    std::vector<std::string> result;

    for (auto i = std::sregex_iterator(std::cbegin(str), std::cend(str), rx); i != std::sregex_iterator(); ++i)
    {
        if ((*i)[1].matched)
            result.push_back(i->str());
    }

    return result;
}

#endif //MODERN_CPP_EXC_VALIDATE_LICENSE_H
