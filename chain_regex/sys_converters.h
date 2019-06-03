//
// Created by takacchi on 28/05/19.
//

#ifndef MODERN_CPP_EXC_SYS_CONVERTERS_H
#define MODERN_CPP_EXC_SYS_CONVERTERS_H

#include <string>
#include <sstream>
#include <iomanip>

/*
 * Define function that converts binary type to string
 */
template <typename Iter>
std::string bytes_to_hexstr(Iter begin, Iter end, bool const uppercase=false)
{
    std::ostringstream output;
    if (uppercase) output.setf(std::ios_base::uppercase);

    for (; begin != end; ++begin)
        output << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(*begin);

    return output.str();

}

/*
 * Define function that converts string to binary type
 */
unsigned char hexchar_to_int(char const ch)
{
    if (ch >= '0' && ch <= '9') return ch - '0';
    if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
    if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
    throw std::invalid_argument("...");
}

// without touching string
std::vector<unsigned char> hexstr_to_bytes(std::string_view hex)
{
    std::vector<unsigned char> result;
    size_t i = 0;

    if (hex.length() % 2 != 0)
    {
        result.push_back(0 | hexchar_to_int(hex[0]));
        i = 1;
    }

    for (; i < hex.length(); i+=2)
    {
        result.push_back( (hexchar_to_int(hex[i]) << 4) | hexchar_to_int(hex[i+1]));
    }

    return result;
}
/*
// changing string
std::vector<unsigned char> hexstr_to_bytes(std::string&& hex)
{
    std::vector<unsigned char> result;

    if (hex.length() % 2 != 0)
        hex = '0' + hex;

    for (size_t i = 0; i < hex.length(); i+=2)
    {
        result.push_back( (hexchar_to_int(hex[i]) << 4) | hexchar_to_int(hex[i+1]));
    }

    return result;
}
*/

// Standard one length delimiter
std::vector<unsigned char> hexstr_to_bytes_delimeter(std::string_view hex, bool delimiter=true)
{
    std::vector<unsigned char> result;

    for (size_t i = 0; i < hex.length(); i+=2)
    {
        result.push_back( (hexchar_to_int(hex[i]) << 4) | hexchar_to_int(hex[i+1]));

        if (delimiter)
            i++;

    }

    return result;
}

// Fancy delimiters

/*std::vector<unsigned char> hexstr_to_bytes_delimeter(std::string_view hex, std::string_view delimiter)
{
    std::vector<unsigned char> result;

    for (size_t i = 0; i < hex.length(); i+=2)
    {
        result.push_back( (hexchar_to_int(hex[i]) << 4) | hexchar_to_int(hex[i+1]));

        i += delimiter.length();
    }

    return result;
}

std::vector<unsigned char> hexstr_to_bytes_delimeter(std::string_view hex)
{
    std::vector<unsigned char> result;

    for (size_t i = 0; i < hex.length(); i+=2)
    {
        while(!isalnum(hex[i]))
            i++;

        result.push_back( (hexchar_to_int(hex[i]) << 4) | hexchar_to_int(hex[i+1]));
    }

    return result;
}
*/
#endif //MODERN_CPP_EXC_SYS_CONVERTERS_H
