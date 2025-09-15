#include <gtest/gtest.h>
#include <iostream>
#include <tuple>
#include <string>

std::tuple<int, int, int, int> parse_ip(const std::string& ip_str) {
    int a, b, c, d;
    std::sscanf(ip_str.c_str(), "%d.%d.%d.%d", &a, &b, &c, &d);
    return std::make_tuple(a, b, c, d);
}

// Тесты
TEST(ParseIpTest, BasicValidIps) {
    auto [a1, b1, c1, d1] = parse_ip("192.168.1.1");
    EXPECT_EQ(a1, 192);
    EXPECT_EQ(b1, 168);
    EXPECT_EQ(c1, 1);
    EXPECT_EQ(d1, 1);
}

TEST(ParseIpTest, EdgeCases) {
    auto [a1, b1, c1, d1] = parse_ip("0.0.0.0");
    EXPECT_EQ(a1, 0);
    EXPECT_EQ(b1, 0);
    EXPECT_EQ(c1, 0);
    EXPECT_EQ(d1, 0);
}


TEST(ParseIpTest, SingleDigitBytes) {
    auto [a, b, c, d] = parse_ip("1.2.3.4");
    EXPECT_EQ(a, 1);
    EXPECT_EQ(b, 2);
    EXPECT_EQ(c, 3);
    EXPECT_EQ(d, 4);
}
int main(int argc, char **argv) {
    std::cout << "Running Google Tests" << std::endl;
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}