#include <ranges>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, std::size_t> lengths;

        std::size_t result = 0;
        for (const auto num : nums)
        {
            if (lengths.contains(num))
            {
                continue;
            }

            const auto& it_before = lengths.find(num - 1);
            const auto& it_after  = lengths.find(num + 1);
            std::size_t before = (it_before != lengths.end()) ? it_before->second : 0;
            std::size_t after = (it_after != lengths.end()) ? it_after->second : 0;
            const auto new_length = 1 + before + after;
            
            lengths[num] = new_length;
            lengths[num - before] = new_length;
            lengths[num + after] = new_length;
            result = std::max(result, new_length);
        }

        return result;
    }
};
