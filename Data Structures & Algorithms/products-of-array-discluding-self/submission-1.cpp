#include <ranges>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix(nums.size(), 1);
        for (const int i : std::views::iota(1, std::ssize(nums)))
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }
        std::vector<int> suffix(nums.size(), 1);
        for (const int i : std::views::iota(0, std::ssize(nums) - 1) | std::views::reverse)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }
        std::vector<int> result(nums.size(), 0);
        for (const int i : std::views::iota(0, std::ssize(nums)))
        {
            result[i] = prefix[i] * suffix[i];
        }
        return result;
    }
};
