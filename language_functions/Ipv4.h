//
// Created by takacchi on 01/05/19.
//

#ifndef MODERN_CPP_EXC_IPV4_H
#define MODERN_CPP_EXC_IPV4_H

#include <array>
#include <sstream>

class Ipv4
{
public:
    constexpr Ipv4(): ip_code{{0}} {}
    constexpr Ipv4(unsigned const char oct_one, unsigned const char oct_two,
                   unsigned const char oct_three, unsigned const char oct_four)
                   : ip_code{{oct_one, oct_two, oct_three, oct_four}} {}

    Ipv4(Ipv4 const & code) : ip_code(code.ip_code) {}

    Ipv4& operator=(const Ipv4&);
    Ipv4& operator++();
    const Ipv4  operator++(int);

    std::string to_string() const;
    unsigned long to_long() const;

public:
    friend std::ostream& operator<<(std::ostream&, const Ipv4&);
    friend std::istream& operator>>(std::istream&, Ipv4&);
    //friend bool operator==(const Ipv4&, const Ipv4&);
    //friend bool operator!=(const Ipv4&, const Ipv4&);
    //friend bool operator<(const Ipv4&, const Ipv4&);
    friend bool operator>(const Ipv4&, const Ipv4&);
    friend bool operator<=(const Ipv4&, const Ipv4&);
    //friend bool operator>=(const Ipv4&, const Ipv4&);

    friend void print_range(const Ipv4&, const Ipv4&);

private:
    explicit constexpr Ipv4(unsigned long a) :
        ip_code{{
                    static_cast<unsigned char>(a >> 24),
                    static_cast<unsigned char>(a >> 16),
                    static_cast<unsigned char>(a >>  8),
                    static_cast<unsigned char>(a)
        }} {}

private:
    std::array<unsigned char, 4> ip_code;
};


#endif //MODERN_CPP_EXC_IPV4_H
