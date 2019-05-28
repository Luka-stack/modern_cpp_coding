//
// Created by takacchi on 20/05/19.
//

#ifndef MODERN_CPP_EXC_GREAT1D_H
#define MODERN_CPP_EXC_GREAT1D_H

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template<class D, size_t size>
class Great1D
{
private:
    typedef D value_type;
    typedef value_type * iterator;
    typedef const value_type const_iterator;

public:
    Great1D() : array(size) {}
    Great1D(std::initializer_list<D> list) : array(list) {}

    constexpr D* data() { return array.data(); }
    constexpr D const* data() const { return array.data(); }

    constexpr D* at(size_t const pos) { return array.at(pos); }
    constexpr D const& at(size_t const pos) const { return  array.at(pos); }

    constexpr D& operator[] (size_t const pos) { return array[pos]; }
    constexpr D const& operator[] (size_t const pos) const { return array[pos]; }

    constexpr bool is_empty() const { return array.size() == 0; }
    constexpr size_t length() const { return array.size(); }

    void fill(D const& value) { std::fill(std::begin(array), std::end(array), value); }
    void clear() { array.clear(); }
    void swap(Great1D& great1D) { array.swap(great1D.array); }
    void push(D const& value) { array.push_back(value); }
    void desc_sort() { std::sort(std::begin(array), std::end(array)); }
    void asc_sort() { std::sort(std::begin(array), std::end(array), std::greater<D>()); }

    const_iterator begin() const { return array.data(); }
    const_iterator end() const { return array.data() + array.size(); }
    iterator begin() { return array.data(); }
    iterator end() { return array.data() + array.size(); }

private:
    std::vector<D> array;

};

template <class D, size_t size>
void print_great1D(Great1D<D, size> const & arr)
{
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void test_great1d()
{
    std::cout << "Starting Great1D Test\n";
    {
        // Fill test
        std::cout << "\nFill Test / 1\n";
        Great1D<int, 3> t;
        t.fill(1);
        print_great1D(t);
    }
    {
        std::cout << "\n Swap test \n";

        Great1D<double, 5> t1 {4.4, 3.2, 1.1, 6.5, 0.6};
        Great1D<double, 5> t2 {14.4, 13.2, 11.1, 16.5, 10.6};

        print_great1D(t1);
        print_great1D(t2);

        t1.swap(t2);

        print_great1D(t1);
        print_great1D(t2);
    }
    {
        std::cout << "\n Print with [] operator test \n";

        Great1D<int, 3> t1 {1, 2, 3};

        for (size_t i = 0; i < t1.length(); i++)
            std::cout << t1[i] << " ";
        std::cout << std::endl;
    }
    {
        std::cout << "\n Iteration test \n";

        Great1D<int, 3> t1 {1, 2, 3};

        for (auto const val : t1)
            std::cout << val << " ";
        std::cout << std::endl;

        std::copy(std::begin(t1), std::end(t1), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
    {
        std::cout << "\n Sort Test \n";

        Great1D<int, 5> t1 {9, 2, 5, 1, -9};

        print_great1D(t1);
        t1.desc_sort();
        print_great1D(t1);
    }
    {
        std::cout << "\n Push Test \n";

        Great1D<int, 5> t1 {9, 2, 5, 1};

        print_great1D(t1);
        t1.push(4);
        print_great1D(t1);
    }
    {
        std::cout << "\n Sort Test \n";

        Great1D<int, 5> t1 {9, 2, 5, 1};

        print_great1D(t1);
        t1.desc_sort();
        print_great1D(t1);
        t1.asc_sort();
        print_great1D(t1);
    }

}

#endif //MODERN_CPP_EXC_GREAT1D_H
