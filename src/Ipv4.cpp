#include "Ipv4.h"

Ipv4::Ipv4(const std::string &Ipv4, char delimiter) : arr_ip{}
{
    if (is_valid_ip(Ipv4))
    {
        std::stringstream ss(Ipv4);
        std::string token;
        size_t i = 0;
        while (std::getline(ss, token, delimiter)) {
            arr_ip[i++] = std::stoul(token);
        }
    }
    else {throw std::invalid_argument("IPv4 address string is malformed");}
}

bool Ipv4::operator>(const Ipv4 &other) {return arr_ip > other.arr_ip;}

bool Ipv4::contains(int value) {return std::find(std::begin(arr_ip), std::end(arr_ip), value) != std::end(arr_ip);}


std::ostream &operator<<(std::ostream &os, const Ipv4 &addr) {
    os << addr.to_string();
    return os;
}
std::string Ipv4::to_string() const
{
    std::stringstream ss;
    ss << arr_ip[0] << "." << arr_ip[1] << "." << arr_ip[2] << "." << arr_ip[3];
    return ss.str();
}