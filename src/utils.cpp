#include "utils.h"

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

bool is_valid_ip(const std::string &ip)
{
    std::regex ipv4regex(
            "(([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9][0-9]|2[0-4][0-9]|25[0-5])");
    return std::regex_match(ip, ipv4regex);
}