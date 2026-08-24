#include <ranges>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> counts;
        for (const auto num : nums)
        {
            counts[num] = counts[num] + 1;
        }
        std::vector<std::vector<int>> frequencies(nums.size() + 1);
        for (const auto count : counts)
        {
            frequencies[count.second].push_back(count.first);
        }
        std::vector<int> result;
        result.reserve(k);
        for (auto it = frequencies.rbegin(); it != frequencies.rend(); ++it)
        {
            const auto& frequency = *it;
            if (frequency.empty())
            {
                continue;
            }
            for (const auto value : frequency)
            {
                result.push_back(value);
            }
            if (result.size() >= k)
            {
                break;
            }
        }

        return result;
    }
};
