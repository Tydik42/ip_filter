#pragma once
#include <string>
#include <ostream>
#include <vector>
#include <sstream>
#include <cstdint>
#include <array>
#include <compare>
#include "utils.h"

class Ipv4
{
    public:
        explicit Ipv4(const std::string &Ipv4, char delimiter = '.');

        uint16_t first() const {return arr_ip[0];}

        uint16_t second() const {return arr_ip[1];}

        uint16_t third() const {return arr_ip[2];}

        uint16_t fourth() const {return arr_ip[3];}

        bool contains(int value);

        bool operator>(const Ipv4 &other);

        std::ostream &operator<<(std::ostream &os) const;

        bool operator==(const Ipv4& rhs) const { return arr_ip == rhs.arr_ip; }

        bool operator!=(const Ipv4& rhs) const { return arr_ip != rhs.arr_ip; }

        bool operator<(const Ipv4& rhs) const { return arr_ip < rhs.arr_ip;   }

        bool operator<=(const Ipv4& rhs) const { return arr_ip <= rhs.arr_ip; }

        bool operator>(const Ipv4& rhs) const { return arr_ip > rhs.arr_ip;   }

        bool operator>=(const Ipv4& rhs) const { return arr_ip >= rhs.arr_ip; }

        std::string to_string();

    private:
        std::array<uint16_t, 4> arr_ip;
};
