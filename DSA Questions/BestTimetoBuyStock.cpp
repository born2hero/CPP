#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int> &prices)
{
    if (prices.empty())
    {
        return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] < minPrice)
        {
            minPrice = prices[i];
        }
        else
        {
            maxProfit = std::max(maxProfit, prices[i] - minPrice);
        }
    }
    return maxProfit;
}

int main()
{
    std::vector<int> prices = {7, 1, 5, 3, 6, 4};
    int result = maxProfit(prices);
    std::cout << "Maximum profit: " << result << std::endl;

    /*
        EXPECTED OUTPUT:
        ----------------
        Maximum profit: 5

    */

    return 0;
}
