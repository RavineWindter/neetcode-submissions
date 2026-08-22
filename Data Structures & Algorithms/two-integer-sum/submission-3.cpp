#include <ranges>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> values;
        for (const int i : std::views::iota(0, std::ssize(nums)))
        {
            const int complement = target - nums[i];
            if (values.contains(complement))
            {
                return {values[complement], i};
            }
            values[nums[i]] = i;
        }
        return {};
    }
};
