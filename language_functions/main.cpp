//
// Created by takacchi on 06/07/19.
//

#include <iostream>
#include <assert.h>
#include "any_args_number.h"
#include "container_function.h"
#include "Great1D.h"
#include "Ipv4.h"
#include "temperature.h"

void check_any_args_number();
void check_container_function();
void check_Great1D();
void check_Ipv4();
void check_temperature();

int main()
{

    check_any_args_number();
    std::cout << "\n\n";

    check_container_function();
    std::cout << "\n\n";

    check_Great1D();
    std::cout << "\n\n";

    check_Ipv4();
    std::cout << "\n\n";

    check_temperature();
    std::cout << "\n\n";

    return 0;
}

void check_any_args_number()
{
    auto build_in_compare = mini_usr(std::greater<>(), 3, 2, 1, 0);
    auto mine_compare = mini_usr(equaly<int>(), 3, 2, 1, 0);
    auto mine_summ = sum_usr(summy<int>(), 3, 2, 1, 0);

    std::cout << "Build in Compare: " << build_in_compare << std::endl;
    std::cout << "Mine Compare: " << mine_compare << std::endl;
    std::cout << "Mine Sum: " << mine_summ << std::endl;
}

void check_container_function()
{
    std::vector<int> cont {1, 2, 3, 4, 5};

    std::cout << "Contains any: 1.[10,9,4,2] | 2.[10,11,12,13]\n";
    std::cout << contains_any(cont, 10, 9, 4, 2) << std::endl;
    std::cout << contains_any(cont, 10, 11, 12, 13) << std::endl;

    std::cout << "\nContains all: 1.[1,2,3,4,5] | 2.[1,2,3,4,19]\n";
    std::cout << contains_all(cont, 1, 2, 3, 4, 5) << std::endl;
    std::cout << contains_all(cont, 1, 2, 3, 4, 19) << std::endl;

    std::cout << "\nContains none: 1.[1,2,3,4, 5] | 2.[10,12,13,14,19]\n";
    std::cout << contains_none(cont, 1, 2, 3, 4, 5) << std::endl;
    std::cout << contains_none(cont, 10, 12, 13, 14, 19) << std::endl;

    std::vector<int> v;
    push_back(v, 1, 2, 3, 4, 5);
    std::copy(std::begin(v), std::end(v), std::ostream_iterator<int>(std::cout, "\n"));

    std::cout << "\n\n";

    std::list<double> l;
    push_back(l, 1.4, 2.2, 3, 4.1, 5.9, 1.4, 2.2, 3, 4.1, 5.9);
    std::copy(std::begin(l), std::end(l), std::ostream_iterator<double>(std::cout, "\n"));
}

void check_Great1D()
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

        for (int i : t1)
            std::cout << i << " ";
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

void check_Ipv4()
{
    Ipv4 ip(168, 192, 0, 1);

    std::cout << "IP: " << ip << " | To String: " << ip.to_string() << std::endl;

    Ipv4 ip_four;
    std::cout << ip_four;
    std::cin >> ip_four;
    if (!std::cin.fail())
        std::cout << ip_four;
}

void check_temperature()
{
    using namespace temperature;
    using namespace temperature_scale_literals;

    auto temp_first{ 36.6_deg };
    auto temp_second{ 92.4_f };
    auto temp_third{ 273.0_k };

    {
        auto fahr = temperature_cast<scale::fahrenheit>(temp_first);
        auto celc = temperature_cast<scale::celsius>(fahr);
        assert(temp_first == celc);
    }
    {
        auto kelv = temperature_cast<scale::kelvin>(temp_first);
        auto celc = temperature_cast<scale::celsius>(kelv);
        assert(temp_first == celc);
    }
}
