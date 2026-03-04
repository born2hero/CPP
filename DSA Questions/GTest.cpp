
/* write gtest */
#include <gtest/gtest.h>

TEST(MaxProfitTest, BasicTest)
{
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int expected = 5;
    int result = maxProfit(prices);
    EXPECT_EQ(expected, result);
}

TEST(MaxProfitTest, EmptyArray)
{
    std::vector<int> prices = {};
    int expected = 0;
    int result = maxProfit(prices);
    EXPECT_EQ(expected, result);
}

TEST(MaxProfitTest, SingleElement)
{
    std::vector<int> prices = {5};
    int expected = 0;
    int result = maxProfit(prices);
    EXPECT_EQ(expected, result);
}