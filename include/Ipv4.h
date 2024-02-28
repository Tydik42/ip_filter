#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <sstream>
#include <cstdint>
#include <array>

class Ipv4
{
    public:
        Ipv4() : arr_ip{0, 0, 0, 0} {};

        explicit Ipv4(const std::string &Ipv4, char delimiter = '.');

        bool contains(int value);

        bool operator>(const Ipv4 &other);

        std::ostream &operator<<(std::ostream &os) const;

        auto operator<=>(const Ipv4& ) const = default;

        std::string to_string();

    private:
        std::array<uint16_t, 4> arr_ip;
};
