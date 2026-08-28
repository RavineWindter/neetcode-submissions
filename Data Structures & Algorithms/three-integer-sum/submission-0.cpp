#include <ranges>

auto TwoSum(std::span<int> nums, int target) -> std::vector<std::vector<int>>
{
    int start = 0;
    int end = std::ssize(nums) - 1;
    int last_good_start = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> result;

    while (start < end)
    {
        if (nums[start] == last_good_start)
        {
            ++start;
            continue;
        }

        const int value = nums[start] + nums[end];
        if (value == target)
        {
            result.emplace_back(std::vector<int>{-target, nums[start], nums[end]});
            last_good_start = nums[start];
            ++start;
        }
        else if (value > target)
        {
            --end;
        }
        else
        {
            ++start;
        }
    }

    return result;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        std::span<int> nums_view(nums);
        std::vector<std::vector<int>> result;
        int current_value = std::numeric_limits<int>::max();
        for (const int i : std::views::iota(0, std::ssize(nums)-2))
        {
            const auto num = nums[i];
            if (num == current_value)
            {
                continue;
            }

            current_value = num;
            const auto triplets = TwoSum(nums_view.subspan(i+1), -current_value);
            for (auto& triplet : triplets)
            {
                result.push_back(std::move(triplet));
            }
        }

        return result;
    }
};
