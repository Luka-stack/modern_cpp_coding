//
// Created by takacchi on 28/05/19.
//

#ifndef MODERN_CPP_EXC_TEMPERATURE_H
#define MODERN_CPP_EXC_TEMPERATURE_H

#include <math.h>

bool are_equal(double const d1, double const d2, double const epsilon = 0.001)
{
    return std::fabs(d1 - d2) < epsilon;
}

namespace temperature
{
    enum class scale { celsius, fahrenheit, kelvin };

    // Class
    template <scale S>
    class Quantity
    {
    public:
        constexpr explicit Quantity(double const am) : amount(am) {}
        explicit operator double() const { return amount; }
    private:
        const double amount;
    };

    // Operators
    template <scale S>
    inline bool operator==(Quantity<S> const& left, Quantity<S> const& right)
    {
        return are_equal(static_cast<double>(left), static_cast<double>(right));
    }

    template <scale S>
    inline bool operator!=(Quantity<S> const& left, Quantity<S> const& right)
    {
        return !(left == right);
    }

    template <scale S>
    inline bool operator<(Quantity<S> const& left, Quantity<S> const& right)
    {
        return static_cast<double>(left) < static_cast<double>(right);
    }

    template <scale S>
    inline bool operator>(Quantity<S> const& left, Quantity<S> const& right)
    {
        return static_cast<double>(left) > static_cast<double>(right);
    }

    template <scale S>
    inline bool operator<=(Quantity<S> const& left, Quantity<S> const& right)
    {
        return !(left > right);
    }

    template <scale S>
    inline bool operator>=(Quantity<S> const& left, Quantity<S> const& right)
    {
        return !(left < right);
    }

    template <scale S>
    constexpr Quantity<S> operator+(Quantity<S> const& qua1, Quantity<S> const& qua2)
    {
        return Quantity<S>(static_cast<double>(qua1) + static_cast<double>(qua2));
    }

    template <scale S>
    constexpr Quantity<S> operator-(Quantity<S> const& qua1, Quantity<S> const& qua2)
    {
        return Quantity<S>(static_cast<double>(qua1) - static_cast<double>(qua2));
    }

    // Converters
    template <scale S, scale T>
    struct conversion_degree
    {
        static double convert(double const value) = delete;
    };

    template <>
    struct conversion_degree<scale::celsius, scale::fahrenheit>
    {
        static double convert(double const value)
        {
            return (value * 9) / 5 + 32;
        }
    };

    template <>
    struct conversion_degree<scale::fahrenheit, scale::celsius>
    {
        static double covert(double const value)
        {
            return (value - 32) * 5 / 9;
        }
    };

    template <>
    struct conversion_degree<scale::celsius, scale::kelvin>
    {
        static double convert(double const value)
        {
            return value + 273.15;
        }
    };

    template <>
    struct conversion_degree<scale::kelvin, scale::celsius>
    {
        static double convert(double const value)
        {
            return value - 273.15;
        }
    };

    template <>
    struct conversion_degree<scale::kelvin, scale::fahrenheit>
    {
        static double convert(double const value)
        {
            return (value - 273.15) * 9/5 + 32;
        }
    };

    template <>
    struct conversion_degree<scale::fahrenheit, scale::kelvin>
    {
        static double convert(double const value)
        {
            return (value - 32) * 5/9 + 273.15;
        }
    };

    template <scale T, scale S>
    constexpr Quantity<T> temperature_cast(Quantity<S> const qua)
    {
        return Quantity<T>(conversion_degree<S, T>::convert(static_cast<double >(qua)));
    }

    //Literal operators
    namespace temperature_scale_literals
    {
            constexpr Quantity<scale::celsius> operator "" _deg(long double const amount)
            {
                return Quantity<scale::celsius> { static_cast<double >(amount) };
            }

            constexpr Quantity<scale::fahrenheit> operator "" _f(long double const amount)
            {
                return Quantity<scale::fahrenheit> { static_cast<double >(amount) };
            }

            constexpr Quantity<scale::kelvin> operator "" _k(long double const amount)
            {
                return Quantity<scale::kelvin> { static_cast<double >(amount) };
            }
    }
}

#endif //MODERN_CPP_EXC_TEMPERATURE_H
