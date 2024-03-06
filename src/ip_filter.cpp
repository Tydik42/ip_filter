#include "Ipv4.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

template<typename C, typename P>
void print(C container, P predicate)
{
    typedef typename C::value_type element_type;
    std::copy_if(container.begin(), container.end(), std::ostream_iterator<element_type>(std::cout, "\n"),
                 predicate);
}


int main() {
    std::vector<Ipv4> ip = read_ip();
    std::sort(ip.begin(), ip.end(), std::greater<>());

    auto no_filtering = [](Ipv4& ip) { return true; };

    auto starts_from_1 = [](Ipv4& ip) { return ip.first() == 1; };

    auto starts_from_4670 = [](Ipv4& ip) { return ip.first() == 46 && ip.second() == 70; };

    auto has_any_46 = [](Ipv4& ip) {
        return ip.first() == 46 || ip.second() == 46 || ip.third() == 46 ||
               ip.fourth() == 46;
    };

    // Print all
    print(ip, no_filtering);

    // Print 1.*.*.*
    print(ip, starts_from_1);

    // Print 46.70.*.*
    print(ip, starts_from_4670);

    // Print 46.*.*.* || *.46.*.* || *.*.46.* || *.*.*.46
    print(ip, has_any_46);
    return 0;
}