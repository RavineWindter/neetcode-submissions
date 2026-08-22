#include <ranges>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> values;
        const auto size = std::ssize(nums);
        for (int i = 0; i < size; ++i)
        {
            const int complement = target - nums[i];
            if (values.contains(complement))
            {
                return {values[complement], i};
            }
            values[nums[i]] = i;
        }
        return {0, 0};
    }
};
