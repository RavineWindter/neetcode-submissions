#include <ranges>

std::string create_histogram(const std::string& str)
{
    std::vector<std::uint8_t> hist(26);
    for (const auto character : str)
    {
        hist[character - 'a'] += 1;
    }
    std::string key;
    for (const auto val : hist)
    {
        key += std::format("{},",val);
    }
    return key;
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> anagrams;

        for (const auto& str : strs)
        {
            anagrams[create_histogram(str)].emplace_back(str);
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagrams.size());
        for (auto& it : anagrams)
        {
            result.emplace_back(std::move(it.second));
        }
        return result;
    }
};
