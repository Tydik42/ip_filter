#include "gtest/gtest.h"
#include "Ipv4.h"

TEST(Ipv4, ConstrucorInvalid)
{
    EXPECT_ANY_THROW(Ipv4(""));
    EXPECT_ANY_THROW(Ipv4("sdgfsdf"));
    EXPECT_ANY_THROW(Ipv4("1...0"));
    EXPECT_ANY_THROW(Ipv4("260.0.1.0"));
    EXPECT_ANY_THROW(Ipv4("1.1.1.01"));
    EXPECT_ANY_THROW(Ipv4("127.1"));
}

// Test constructor with valid argument
TEST(Ipv4, ConstructorValid)
{
    EXPECT_NO_THROW(Ipv4("127.0.0.1"));
    EXPECT_NO_THROW(Ipv4("192.168.1.1"));
    EXPECT_NO_THROW(Ipv4("192.168.1.255"));
    EXPECT_NO_THROW(Ipv4("255.255.255.255"));
    EXPECT_NO_THROW(Ipv4("0.0.0.0"));
}

TEST(Ipv4, ConstructorComparation)
{
    auto addr1 = Ipv4("127.0.0.1");
    auto addr2 = Ipv4("192.168.1.1");
    auto addr3 = Ipv4("192.169.1.1");
    auto addr4 = Ipv4("192.169.1.1");
    EXPECT_TRUE(addr2 > addr1);
    EXPECT_TRUE(addr3 > addr2);
    EXPECT_TRUE(addr3 == addr4);
    EXPECT_TRUE(addr3 >= addr4);
    EXPECT_TRUE(addr3 <= addr4);
    EXPECT_TRUE(addr1 < addr4);
}