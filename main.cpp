#include "fixpoint.hpp"

#include <iostream>

constexpr Fix h = {4};

int main()
{
    constexpr Fix a(34.5);
    Fix b(23.4);
    Fix c(123);

    Fix d(1.5);
    Fix e(2.1);

    std::cout << static_cast<double>(a - b) << "\n";
    std::cout << static_cast<double>(d / 2.0_fx) << "\n";
    std::cout << static_cast<uint16_t>(c / 2.0_fx) << "\n";
    std::cout << static_cast<double>(a >> 1) << "\n";
    std::cout << std::boolalpha << std::is_standard_layout<Fix>() << "\n";
    std::cout << std::boolalpha << std::is_trivial<Fix>() << "\n";
    std::cout << std::boolalpha << (sizeof(Fix) <= 2 * sizeof(void*)) << "\n";
    std::cout << static_cast<double>(45.3_fx + Fix(true)) << "\n";

    return 0;
}
