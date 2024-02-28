#include "utils.h"

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