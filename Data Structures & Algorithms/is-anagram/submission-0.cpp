class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t .size())
        {
            return false;
        }

        constexpr std::size_t size = 'z' - 'a' + 1;
        std::array<int, size> char_count;

        for (const auto character : s)
        {
            char_count[character - 'a'] += 1;
        }
        for (const auto character : t)
        {
            char_count[character - 'a'] -= 1;
        }

        for (const auto count : char_count)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }
};
