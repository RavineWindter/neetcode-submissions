#include <ranges>

using Histogram = std::vector<std::uint8_t>;

Histogram create_histogram(const std::string& str)
{
    Histogram hist(26);
    for (const auto character : str)
    {
        hist[character - 'a'] += 1;
    }
    return hist;
}

struct HistogramHash
{
    std::size_t operator()(const Histogram& hist) const
    {
        std::size_t result = 0;
        for (std::uint8_t count : hist) {
            result ^= std::hash<std::uint8_t>{}(count) + 0x9e3779b9 + (result << 6) + (result >> 2);
        }
        return result;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<Histogram, std::vector<std::string>, HistogramHash> anagrams;

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
