class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int profit = 0;

        for (const int price: prices)
        {
            min_price = std::min(min_price, price);
            profit = std::max(profit, price - min_price);
        }

        return profit;
    }
};
