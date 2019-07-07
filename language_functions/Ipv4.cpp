#include <iostream>
#include "Ipv4.h"
//
// Created by takacchi on 01/05/19.
//
Ipv4 &Ipv4::operator=(const Ipv4& code)
{
    ip_code = code.ip_code;
    return *this;
}

std::string Ipv4::to_string() const
{
    std::stringstream ip;
    ip << *this;
    return ip.str();
}

std::ostream &operator<<(std::ostream& os, const Ipv4& code)
{
    os << static_cast<int>(code.ip_code[0]) << '.'
       << static_cast<int>(code.ip_code[1]) << '.'
       << static_cast<int>(code.ip_code[2]) << '.'
       << static_cast<int>(code.ip_code[3]) << '\n';

    return os;
}

std::istream &operator>>(std::istream& is, Ipv4& code)
{
    char com1, com2, com3;
    int oct1, oct2, oct3, oct4;

    is >> oct1 >> com1 >> oct2 >> com2 >> oct3 >> com3 >> oct4;
    if (com1 == '.' && com2 == '.' && com3 == '.')
        code = Ipv4(oct1, oct2, oct3, oct4);
    else
        is.setstate(std::ios_base::failbit);

    return is;
}

unsigned long Ipv4::to_long() const
{
    return (static_cast<unsigned long>(ip_code[0]) << 24) |
           (static_cast<unsigned long>(ip_code[1]) << 16) |
           (static_cast<unsigned long>(ip_code[2]) <<  8) |
            static_cast<unsigned long>(ip_code[3]);
}

Ipv4& Ipv4::operator++()
{
    *this = Ipv4(1 + to_long());
    return *this;
}

const Ipv4  Ipv4::operator++(int)
{
    Ipv4 tmp(*this);
    ++(*this);
    return *this;
}

/*bool operator==(const Ipv4& obj1, const Ipv4& obj2)
{
    // return obj1.to_long() == obj2.to_long();
    return obj1.ip_code == obj2.ip_code;
}

bool operator!=(const Ipv4& obj1, const Ipv4& obj2)
{
    // return !(obj1.to_long == obj2.to_long());
    return !(obj1 == obj2);
}*/

/*bool operator<(const Ipv4& obj1, const Ipv4& obj2)
{
    return obj1.to_long() < obj2.to_long();
}*/

bool operator>(const Ipv4& obj1, const Ipv4& obj2)
{
    return obj1.to_long() > obj2.to_long();
}

bool operator<=(const Ipv4& obj1, const Ipv4& obj2)
{
    return obj1.to_long() <= obj2.to_long();
}

/*bool operator>=(const Ipv4& obj1, const Ipv4& obj2)
{
    return obj1.to_long() >= obj2.to_long();
}*/

void print_range(const Ipv4& from, const Ipv4& till)
{
    if (till > from)
    {
        for (Ipv4 tmp = from; from <= till; tmp++)
            std::cout << tmp << std::endl;
    }

    std::cerr << "Attention! Wrong Range!\n";


}



