//
// Created by takacchi on 04/06/19.
//

#ifndef MODERN_CPP_EXC_DATE_TRANSFORM_H
#define MODERN_CPP_EXC_DATE_TRANSFORM_H

#include <iostream>
#include <regex>

// format dd.mm.rrrr or dd/mm/rrrr to rrr-mm-dd
// regex (\d{1,2}) (\.|-|/) (\d{1,2}) (\.|-|/) (\d{4})

std::string date_transform(std::string_view date)
{
    auto rx = std::regex{ R"((\{1,2})(\.|-|/)(\d{1,2})(\.|-|/)(\d{4}))" };
    return std::regex_replace(date.data(), rx, R"($5-$3-$1)");
}

#endif //MODERN_CPP_EXC_DATE_TRANSFORM_H
