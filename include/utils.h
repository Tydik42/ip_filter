#pragma once

#include "Ipv4.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <regex>

template<typename C, typename P>
void print(C container, P predicate);

std::vector<Ipv4> read_ip();

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

bool is_valid_ip(const std::string &ip);