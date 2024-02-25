#include "Ipv4.h"

class Ipv4
{
    explicit Ipv4(const std::string& Ipv4, const char delimiter = '.')
    {
        std::stringstream ss(Ipv4);
        std::string token;
        while (std::getline(ss, token, delimiter))
        {
            arr_ip.push_back(std::stoul(token));
        }
    }

    bool operator > (const Ipv4& other)
    {
        return arr_ip > other.arr_ip;
    }

    bool contains (int value)
    {
        return std::find(arr_ip.begin(), arr_ip.end(), value) != arr_ip.end();
    }
};