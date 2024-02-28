#pragma once

#include "Ipv4.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

template<typename C, typename P>
void print(C container, P predicate)
{
    typedef typename C::value_type element_type;
    std::copy_if(container.begin(), container.end(), std::ostream_iterator<element_type>(std::cout, "\n"),
                 predicate);
}

std::vector<Ipv4> read_ip()
{
    std::vector<Ipv4> data;
    std::string input;
    while (std::getline(std::cin, input))
    {
        auto address = Ipv4(input.substr(0, input.find('\t')));
        data.push_back(address);
    }
    return data;
}

auto no_filtering = []() { return true; };

// Print 1.*.*.*
auto starts_from_1 = [](const Ipv4 ip) { return ip.first() == 1; };

// Print 46.70.*.*
auto starts_from_4670 = [](const Ipv4 ip) { return ip.first() == 46 && ip.second() == 70; };

// Print 46.*.*.* || *.46.*.* || *.*.46.* || *.*.*.46
auto has_any_46 = [](const Ipv4 ip) {
    return ip.first() == 46 || ip.second() == 46 || ip.third() == 46 ||
           ip.fourth() == 46;
};