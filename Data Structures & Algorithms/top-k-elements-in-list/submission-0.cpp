#include <ranges>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (const auto num : nums)
        {
            counts[num] = counts.contains(num) ? counts[num] + 1 : 1;
        }
        auto result = counts | std::views::keys | std::ranges::to<std::vector>();
        std::ranges::sort(result,
            [&](const int x, const int y) { return counts[x] > counts[y]; });
        return result | std::views::take(k) | std::ranges::to<std::vector>();
    }
};
