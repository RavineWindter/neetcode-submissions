#include <ranges>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> values;
        for (const auto i : std::views::iota(0, std::ssize(nums)))
        {
            const auto complement = values.find(target - nums[i]);
            if (complement != values.end())
            {
                return {complement->second, i};
            }
            values[nums[i]] = i;
        }
        return {0, 0};
    }
};
