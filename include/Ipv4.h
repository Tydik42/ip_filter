#pragma once
#include <string>
#include <oastream>
#include <vector>
#include <sstream>

class Ipv4
{
public:
    Ipv4() : arr_ip{0, 0, 0, 0}

    explicit Ipv4(const std::string& Ipv4, const char delimiter = '.');

    bool contains(const uint16_1 value);

    bool operator > (const Ipv4& other);

private:
    std::array<uint16_t, 4> arr_ip;
};