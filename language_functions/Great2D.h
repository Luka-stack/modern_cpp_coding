//
// Created by takacchi on 06/05/19.
//

#ifndef MODERN_CPP_EXC_GREAT2D_H
#define MODERN_CPP_EXC_GREAT2D_H

#include <iostream>
#include <vector>

template <class D, size_t R, size_t C>
class Great2D
{
private:
    typedef D value_type;
    typedef value_type * iterator;
    typedef const value_type const_iterator;

public:
    Great2D() : rep(R * C) {};
    Great2D(std::initializer_list<D> list) : rep(list) {};

    constexpr D* data() { return rep.data(); };
    constexpr  D const* data() const { return rep.data(); }

    constexpr D& at(size_t const row, size_t const col) { return rep.at(col * C + row); }
    constexpr D const& at(size_t const row, size_t const col) const { return rep.at(col * C + row); }

    constexpr D& operator() (size_t const row, size_t const col) { return rep[col * C + row]; }
    constexpr D const& operator() (size_t const row, size_t col) const { return rep[col * C + row]; }

    constexpr bool is_empty() const { return rep.size() == 0; }
    constexpr size_t size(int const dimension=0) const
    {
        if (dimension == 1) return R;
        if (dimension == 2) return C;
        if (dimension == 0) return rep.size();
        throw std::out_of_range("Wrong Dimension! 1 - Row, 2 - Col, 0 - Array");
    }

    void fill(D const& value) { std::fill(rep.begin(), rep.end(), value); }
    void swap(Great2D& in_array) { rep.swap(in_array); }

    const_iterator begin() const { return rep.data(); }
    const_iterator end() const { return rep.data() + rep.size(); }
    iterator begin() { return rep.data(); }
    iterator end() { return rep.data() + rep.size(); }

    // friends
    friend std::istream& operator>>(std::istream& in, Great2D& in_array)
    {
        in >> in_array.rep.front();

        return in;
    }

    friend std::ostream& operator<<(std::ostream& ot, Great2D const & in_array)
    {
        for (int i = 0; i < in_array.size(); i++)
        {
            int row = i % R;
            int col = i % C;

            if (row == 0)
                ot << "Row: " << i / R << '\n';

            ot << "[" << col << "]: " << in_array.at(row, col) << "  ";

            if (col == C-1)
                ot << '\n';
        }

        return ot;
    }

private:
    std::vector<D> rep;
};


#endif //MODERN_CPP_EXC_GREAT2D_H
