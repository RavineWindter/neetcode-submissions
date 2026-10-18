class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> positions;
        const int N = s.size();
        int start = 0;
        int max_length = 0;

        for (std::size_t i = 0; i < N; ++i)
        {
            if (positions.contains(s[i]))
            {
                start = std::max(start, positions[s[i]] + 1);
            }
            positions[s[i]] = i;

            const int length = i - start + 1;
            max_length = std::max(max_length, length);
        }

        return max_length;
    }
};
