#include <ranges>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> result(nums.size(), 1);
        for (const int i : std::views::iota(1, std::ssize(nums)))
        {
            result[i] = result[i-1] * nums[i-1];
        }
        int suffix = 1;
        for (const int i : std::views::iota(0, std::ssize(nums) - 1) | std::views::reverse)
        {
            suffix *= nums[i+1];
            result[i] *= suffix;
        }
        return result;
    }
};
