#include "Ipv4.h"
#include <algorithm> // for std::find

Ipv4::Ipv4(const std::string &Ipv4, char delimiter) : arr_ip{}
{
    std::stringstream ss(Ipv4);
    std::string token;
    size_t i = 0;
    while (std::getline(ss, token, delimiter)) {
        arr_ip[i++] = std::stoul(token);
    }
}

bool Ipv4::operator>(const Ipv4 &other) {return arr_ip > other.arr_ip;}

bool Ipv4::contains(int value) {return std::find(std::begin(arr_ip), std::end(arr_ip), value) != std::end(arr_ip);}