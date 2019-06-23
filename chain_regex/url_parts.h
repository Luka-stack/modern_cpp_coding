//
// Created by takacchi on 04/06/19.
//

#ifndef MODERN_CPP_EXC_URL_PARTS_H
#define MODERN_CPP_EXC_URL_PARTS_H

#include <iostream>
#include <optional>
#include <regex>

struct url_parts
{
    std::string protocol;
    std::string domain;
    std::optional<unsigned> port;
    std::optional<std::string> path;
    std::optional<std::string> query;
    std::optional<std::string> fragment;
};

std::optional<url_parts> parse_url(std::string url)
{
    std::regex rx(R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/\.]+)?(\?([\w=&]*)(#?(\w+))?)?$)");
    auto matches = std::smatch{};

    if (std::regex_match(url, matches, rx))
    {
        if (matches[1].matched && matches[2].matched)
        {
            url_parts whole_url;

            whole_url.protocol = matches[1].str();
            whole_url.domain = matches[2].str();

            if (matches[4].matched)
                whole_url.port = std::stoi(matches[4]);
            if (matches[5].matched)
                whole_url.path = matches[5];
            if (matches[7].matched)
                whole_url.query = matches[7];
            if (matches[9].matched)
                whole_url.fragment = matches[9];
            return whole_url;
        }
    }

    return {};
}

/*
 * ^ - beginning
 * [] - character set
 * /w - any word character
 * + - match 1 or more of the preceding token
 * * - Matches 0 or more of the preceding token.
 * . - matches any character except line breaks
 * ? - optional
 */

#endif //MODERN_CPP_EXC_URL_PARTS_H
