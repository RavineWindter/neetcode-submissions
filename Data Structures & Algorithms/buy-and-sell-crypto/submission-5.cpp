class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int start = 0;
        int end = 1;
        int profit = 0;
        const int N = prices.size();

        while (end < N)
        {
            const int price_start = prices[start];
            const int price_end = prices[end];
            const int diff = price_end - price_start;

            profit = diff > profit ? diff : profit;

            if (prices[end] < prices[start])
            {
                start = end;
            }
            ++end;
        }

        return profit;
    }
};
