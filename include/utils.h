#pragma once

#include "Ipv4.h"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <regex>

std::vector<Ipv4> read_ip();

bool is_valid_ip(const std::string &ip);