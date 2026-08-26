#include <ranges>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> values(nums.begin(), nums.end());

        int result = 0;
        for (const auto value : values)
        {
            if (values.contains(value-1))
            {
                continue;
            }

            int length = 1;
            while (values.contains(value + length))
            {
                ++length;
            }
            result = std::max(result, length);
        }

        return result;
    }
};
